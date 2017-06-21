
// Qt
#include <QDebug>

// Application
#include "CTDMADevice.h"

//-------------------------------------------------------------------------------------------------

// #define CONSOLE_DEBUG(a)	qDebug() << a;
#define CONSOLE_DEBUG(a)

//-------------------------------------------------------------------------------------------------

PTDMASlot CTDMADevice::s_ucBadSlot		= 0;
PTDMASlot CTDMADevice::s_ucFirstSlot	= 1;
PTDMASlot CTDMADevice::s_ucLastSlot		= 250;

//-------------------------------------------------------------------------------------------------

/*!
    \class CTDMADevice
    \inmodule qt-plus
    \brief A Time Division Multiple Access class. Can input/output from any QIODevice.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CTDMADevice. \br\br
    \a pDevice is the input/output stream.
    \a tSeriaNumber is a unique serial number for this entity
    \a iMaxBytesPerSecond is not used yet
    \a bIsMaster tells if this TDMA entity is master (true) or slave (false)
*/
CTDMADevice::CTDMADevice(QIODevice* pDevice, PTDMASerial tSeriaNumber, int iMaxBytesPerSecond, bool bIsMaster)
    : m_pDevice(pDevice)
    , m_tSeriaNumber(tSeriaNumber)
    , m_tSlot(s_ucBadSlot)
    , m_tTimer(this)
    , m_tLastInputTime(QDateTime::currentDateTime())
    , m_tLastSpeakTime(QDateTime::currentDateTime())
    , m_tPowerOnTime(QDateTime::currentDateTime())
    , m_iMaxBytesPerSecond(iMaxBytesPerSecond)
    , m_iMaxBytesPerSlot(1)
    , m_iNumFramesBeforeIdent(0)
    , m_bIsMaster(bIsMaster)
    , m_bAntennaPowered(false)
{
    static bool bSrandInit = false;

    if (bSrandInit == false)
    {
        bSrandInit = true;

        // Initialize random numbers
        qsrand(QDateTime::currentDateTime().toTime_t());
    }

    // Connect to IO device
    connect(m_pDevice, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    connect(&m_tTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    if (m_bIsMaster)
    {
        m_tTimer.setInterval(10);
    }
    else
    {
        m_tTimer.setInterval(500);
        handleReset_Slave();
    }

    m_tTimer.start();

    QIODevice::open(QIODevice::ReadWrite);
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CTDMADevice.
*/
CTDMADevice::~CTDMADevice()
{
    QIODevice::close();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the serial number of this TDMA entity.
*/
PTDMASerial CTDMADevice::getSerialNumber() const
{
    return m_tSeriaNumber;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns all serial numbers that are registered in this TDMA entity.
*/
QVector<PTDMASerial> CTDMADevice::getAllUserSerialNumbers() const
{
    QVector<PTDMASerial> vSerials;

    foreach (const CClient& client, m_mRegisteredUsers)
    {
        vSerials.append(client.m_tSerialNumber);
    }

    return vSerials;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns true as TDMA is sequential.
*/
bool CTDMADevice::isSequential() const
{
    return true;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns available bytes to read.
*/
qint64 CTDMADevice::bytesAvailable() const
{
    if (m_baInput.count() > 0) return m_baInput.count();

    foreach (PTDMASlot ucSlot, m_mRegisteredUsers.keys())
    {
        if (m_mRegisteredUsers[ucSlot].m_baData.count() > 0)
        {
            return m_mRegisteredUsers[ucSlot].m_baData.count();
        }
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the number of bytes to write.
*/
qint64 CTDMADevice::bytesToWrite() const
{
    return m_baOutput.count();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns data read for the entity identified by \a uiSerialNumber.
*/
QByteArray CTDMADevice::readFromSerial(quint16 uiSerialNumber)
{
    foreach (PTDMASlot ucSlot, m_mRegisteredUsers.keys())
    {
        if (m_mRegisteredUsers[ucSlot].m_tSerialNumber == uiSerialNumber)
        {
            QByteArray baReturnValue = m_mRegisteredUsers[ucSlot].m_baData;
            m_mRegisteredUsers[ucSlot].m_baData.clear();

            return baReturnValue;
        }
    }

    return QByteArray();
}

//-------------------------------------------------------------------------------------------------

/*!
    Meant to be implemented by subclasses when it is time to turn on any comm device, like an antenna. \br\br
    Returns a power on time in milliseconds.
*/
int CTDMADevice::powerOn()
{
    CONSOLE_DEBUG(QString("Power on from %1").arg(m_tSeriaNumber));

    return 10;
}

//-------------------------------------------------------------------------------------------------

/*!
    Meant to be implemented by subclasses when it is time to turn off any comm device, like an antenna.
*/
void CTDMADevice::powerOff()
{
    CONSOLE_DEBUG(QString("Power off from %1").arg(m_tSeriaNumber));
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::onTimeout()
{
    if (m_bIsMaster)
    {
        if (m_tLastInputTime.msecsTo(QDateTime::currentDateTime()) > 50)
        {
            m_tLastInputTime = QDateTime::currentDateTime();

            sendSpeak();
        }
    }
    else
    {
        if (m_tLastSpeakTime.secsTo(QDateTime::currentDateTime()) > 3)
        {
            if (m_bAntennaPowered)
            {
                m_bAntennaPowered = false;

                powerOff();
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::onReadyRead()
{
    m_tLastInputTime = QDateTime::currentDateTime();

    m_baRawInput.append(m_pDevice->read(256));

    if (m_baRawInput.count() > 0)
    {
        int iBytesUsed = processInput(m_baRawInput);

        if (iBytesUsed == -1)
        {
            m_baRawInput.clear();
        }

        m_baRawInput = m_baRawInput.mid(iBytesUsed);
    }
}

//-------------------------------------------------------------------------------------------------

int CTDMADevice::processInput(const QByteArray& baData)
{
    if (m_bIsMaster)
    {
        return processInput_Master(baData);
    }
    else
    {
        return processInput_Slave(baData);
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

int CTDMADevice::processInput_Master(const QByteArray& baData)
{
    PTDMAAction ucAction = baData[0];

    switch (ucAction)
    {
        case aSlaveSpeakResponse:
        {
            const TSlaveData_SlaveSpeak* pSpeak = (const TSlaveData_SlaveSpeak*) baData.constData();

            handleSlaveSpeak_Master(pSpeak, baData.mid(sizeof(TSlaveData_SlaveSpeak)));

            return sizeof(TSlaveData_SlaveSpeak) + pSpeak->ucNumBytes;
        }
            break;

        case aSetSlotResponse:
        {
            const TSlaveData_SetSlot* pSetSlot = (const TSlaveData_SetSlot*) baData.constData();

            // Message sanity check and processing
            if (pSetSlot->ucAction == pSetSlot->ucActionEcho)
            {
                handleSetSlot_Master(pSetSlot);

                return sizeof(TSlaveData_SetSlot);
            }
            else
            {
                // Jam, order a reset for non registered slaves
                sendReset();

                return -1;
            }
        }
            break;

        case aAnyoneResponse:
        {
            const TSlaveData_Anyone* pAnyone = (const TSlaveData_Anyone*) baData.constData();

            // Message sanity check and processing
            if (pAnyone->ucAction == pAnyone->ucActionEcho)
            {
                handleNewUser_Master(pAnyone);

                return sizeof(TSlaveData_Anyone);
            }
            else
            {
                // Jam, order a reset for non registered slaves
                sendReset();

                return -1;
            }
        }
            break;
    }

    return -1;
}

//-------------------------------------------------------------------------------------------------

int CTDMADevice::processInput_Slave(const QByteArray& baData)
{
    PTDMAAction ucAction = baData[0];

    switch (ucAction)
    {
        // Raw incoming data
        case aMasterSpeak:
        {
            // Append input data
            m_baInput.append(baData);

            // Tell the world that data is available for reading
            emit readyRead();

            return baData.count();
        }
            break;

        // Raw outgoing data
        case aSlaveSpeak:
        {
            const TMasterData_SlaveSpeak* pSpeak = (const TMasterData_SlaveSpeak*) baData.constData();

            handleSpeak_Slave(pSpeak);

            return sizeof(TMasterData_SlaveSpeak);
        }
            break;

        // Raw data form a slave
        case aSlaveSpeakResponse:
        {
            const TSlaveData_SlaveSpeak* pSpeak = (const TSlaveData_SlaveSpeak*) baData.constData();

            return sizeof(TSlaveData_SlaveSpeak) + pSpeak->ucNumBytes;
        }
            break;

        // Slot assignment
        case aSetSlot:
        {
            const TMasterData_SetSlot* pSetSlot = (const TMasterData_SetSlot*) baData.constData();

            if (pSetSlot->ucAction == pSetSlot->ucActionEcho)
            {
                handleSetSlot_Slave(pSetSlot);

                return sizeof(TMasterData_SetSlot);
            }
            else
            {
                return -1;
            }
        }
            break;

        // A slave acknowledging a slot
        case aSetSlotResponse:
        {
            const TSlaveData_SetSlot* pSetSlot = (const TSlaveData_SetSlot*) baData.constData();

            return sizeof(TSlaveData_SetSlot);
        }
            break;

        // Anyone here?
        case aAnyone:
        {
            handleAnyone_Slave();

            return 1;
        }
            break;

        // Response to "anyone here?"
        case aAnyoneResponse:
        {
            const TSlaveData_Anyone* pAnyone = (const TSlaveData_Anyone*) baData.constData();

            return sizeof(TSlaveData_Anyone);
        }
            break;

        // Everyone will talk in turn...
        case aReset:
        {
            handleReset_Slave();

            return 1;
        }
            break;
    }

    return -1;
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::handleSlaveSpeak_Master(const TSlaveData_SlaveSpeak* pSpeak, const QByteArray& baData)
{
    CONSOLE_DEBUG(QString("Master receiving data from slot %1").arg(m_tSlot));
    CONSOLE_DEBUG("... " << baData);

    // Read data from the current slave (m_ucSlot)
    if (m_mRegisteredUsers.contains(m_tSlot))
    {
        m_mRegisteredUsers[m_tSlot].m_baData.append(baData);
        m_mRegisteredUsers[m_tSlot].m_tLastSpeakTime = QDateTime::currentDateTime();
    }

    // On envoie le signal de données arrivées
    emit readyRead();

    sendSpeak();
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::handleNewUser_Master(const TSlaveData_Anyone* pAnyone)
{
    for (int iIndex = 0; iIndex < m_vNewUsers.count(); iIndex++)
    {
        if (m_vNewUsers[iIndex].m_tSerialNumber == pAnyone->uiSerialNumber)
        {
            m_vNewUsers.remove(iIndex);
            break;
        }
    }

    m_vNewUsers.append(CClient(pAnyone->uiSerialNumber, getFreeSlot()));

    CONSOLE_DEBUG("Master added new user : " << QString::number((int) pAnyone->uiSerialNumber));
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::handleSetSlot_Master(const TSlaveData_SetSlot* pSetSlot)
{
    CONSOLE_DEBUG("Master receiving aSetSlotResponse for " << QString::number((int) pSetSlot->uiSerialNumber) << " : " << QString::number((int) pSetSlot->ucSlot));

    if (m_mRegisteredUsers.contains(pSetSlot->ucSlot))
    {
        m_mRegisteredUsers.remove(pSetSlot->ucSlot);
    }

    for (int iIndex = 0; iIndex < m_vNewUsers.count(); iIndex++)
    {
        if (m_vNewUsers[iIndex].m_tSerialNumber == pSetSlot->uiSerialNumber)
        {
            m_mRegisteredUsers[pSetSlot->ucSlot] = m_vNewUsers[iIndex];
            m_vNewUsers.remove(iIndex);

            CONSOLE_DEBUG("Master added registered user : " << QString::number((int) m_mRegisteredUsers[pSetSlot->ucSlot].m_tSerialNumber) << " at slot " << QString::number((int) m_mRegisteredUsers[pSetSlot->ucSlot].m_tSlot));

            break;
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::handleSpeak_Slave(const TMasterData_SlaveSpeak* pSpeak)
{
    if (pSpeak->ucSlot == m_tSlot)
    {
        if (m_baOutput.count() > 0)
        {
            QByteArray baOut = m_baOutput.left(m_iMaxBytesPerSlot);
            m_baOutput = m_baOutput.mid(baOut.count());

            TSlaveData_SlaveSpeak tSpeak;

            tSpeak.ucAction = aSlaveSpeakResponse;
            tSpeak.ucNumBytes = baOut.count();

            m_pDevice->write((const char*) &tSpeak, sizeof(TSlaveData_SlaveSpeak));
            m_pDevice->write(baOut);

            m_tLastSpeakTime = QDateTime::currentDateTime();
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::handleSetSlot_Slave(const TMasterData_SetSlot* pSetSlot)
{
    if (pSetSlot->uiSerialNumber == m_tSeriaNumber)
    {
        CONSOLE_DEBUG("Slave receiving aSetSlot for " << QString::number(pSetSlot->uiSerialNumber) << " : " << QString::number(pSetSlot->ucSlot));

        m_tSlot = pSetSlot->ucSlot;
        m_iMaxBytesPerSlot = pSetSlot->ucMaxBytesPerSlot;

        TSlaveData_SetSlot tAnswer;

        tAnswer.ucAction = aSetSlotResponse;
        tAnswer.uiSerialNumber = m_tSeriaNumber;
        tAnswer.ucSlot = m_tSlot;
        tAnswer.ucActionEcho = aSetSlotResponse;

        CONSOLE_DEBUG("Slave sending aSetSlotResponse for " << QString::number((int) m_tSeriaNumber) << " : " << QString::number((int) m_tSlot));

        m_pDevice->write((const char*) &tAnswer, sizeof(TSlaveData_SetSlot));

        m_tLastSpeakTime = QDateTime::currentDateTime();
    }
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::handleAnyone_Slave()
{
    if (m_tSlot == s_ucBadSlot)
    {
        if (m_iNumFramesBeforeIdent == 0)
        {
            TSlaveData_Anyone tAnswer;

            tAnswer.ucAction = aAnyoneResponse;
            tAnswer.uiSerialNumber = m_tSeriaNumber;
            tAnswer.ucActionEcho = aAnyoneResponse;

            m_pDevice->write((const char*) &tAnswer, sizeof(TSlaveData_Anyone));

            m_tLastSpeakTime = QDateTime::currentDateTime();
        }
        else
        {
            m_iNumFramesBeforeIdent--;
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::handleReset_Slave()
{
    if (m_tSlot == s_ucBadSlot && m_iNumFramesBeforeIdent == 0)
    {
        m_iNumFramesBeforeIdent = 1 + (qrand() % 10);

        CONSOLE_DEBUG(QString("Slave set m_iNumFramesBeforeIdent to %1").arg(m_iNumFramesBeforeIdent));
    }
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::sendSpeak()
{
    if (m_mRegisteredUsers.count() > 0)
    {
        // Move on to next slave
        m_tSlot++;

        // If the slot is unused, go to bad slot
        if (m_tSlot > m_mRegisteredUsers.count())
        {
            m_tSlot = s_ucBadSlot;

            sendSetSlot();
        }
        else
        {
            CONSOLE_DEBUG("Master sending aSlaveSpeak for slot " << m_tSlot);

            TMasterData_SlaveSpeak tSpeak;

            tSpeak.ucAction = aSlaveSpeak;
            tSpeak.ucSlot = m_tSlot;

            m_pDevice->write((const char *) &tSpeak, sizeof(TMasterData_SlaveSpeak));
        }
    }
    else
    {
        m_tSlot = s_ucBadSlot;

        sendSetSlot();
    }
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::sendSetSlot()
{
    if (m_vNewUsers.count() > 0)
    {
        CONSOLE_DEBUG("Master sending SetSlot for " << QString::number(m_vNewUsers[0].m_tSerialNumber) << " : " << QString::number(m_vNewUsers[0].m_tSlot));

        TMasterData_SetSlot tSetSlot;

        tSetSlot.ucAction = aSetSlot;
        tSetSlot.uiSerialNumber = m_vNewUsers[0].m_tSerialNumber;
        tSetSlot.ucSlot = m_vNewUsers[0].m_tSlot;
        tSetSlot.ucMaxBytesPerSlot = 4;
        tSetSlot.ucActionEcho = aSetSlot;

        m_pDevice->write((const char *) &tSetSlot, sizeof(TMasterData_SetSlot));
    }
    else
    {
        sendAnyone();
    }
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::sendAnyone()
{
    CONSOLE_DEBUG("Master sending Anyone");

    m_pDevice->write(QByteArray(1, aAnyone));
}

//-------------------------------------------------------------------------------------------------

void CTDMADevice::sendReset()
{
    CONSOLE_DEBUG("Master sending Reset");

    m_pDevice->write(QByteArray(1, aReset));
}

//-------------------------------------------------------------------------------------------------

PTDMASlot CTDMADevice::getFreeSlot() const
{
    for (PTDMASlot ucIndex = s_ucFirstSlot; ucIndex <= s_ucLastSlot; ucIndex++)
    {
        bool bUsed = false;

        foreach (const CClient& tClient, m_vNewUsers)
        {
            if (tClient.m_tSlot == ucIndex)
            {
                bUsed = true;
                break;
            }
        }

        if (bUsed == false)
        {
            foreach (PTDMASlot ucSlot, m_mRegisteredUsers.keys())
            {
                if (ucSlot == ucIndex)
                {
                    bUsed = true;
                    break;
                }
            }
        }

        if (bUsed == false)
        {
            return ucIndex;
        }
    }

    return s_ucBadSlot;
}

//-------------------------------------------------------------------------------------------------

qint64 CTDMADevice::readData(char* data, qint64 maxSize)
{
    qint64 iSize = maxSize;

    if (iSize > m_baInput.count())
    {
        iSize = m_baInput.count();
    }

    if (iSize > 0)
    {
        memcpy(data, m_baInput.constData(), iSize);
    }

    m_baInput = m_baInput.right(m_baInput.count() - iSize);

    return iSize;
}

//-------------------------------------------------------------------------------------------------

qint64 CTDMADevice::writeData(const char* pData, qint64 iSize)
{
    m_baOutput.append(QByteArray(pData, iSize));

    if (m_bAntennaPowered == false)
    {
        m_bAntennaPowered = true;
        m_tPowerOnTime = QDateTime::currentDateTime();
        m_tLastSpeakTime = QDateTime::currentDateTime();

        int iPowerOnMS = powerOn();
    }

    return iSize;
}
