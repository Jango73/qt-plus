
// Qt
#include <QDebug>

// Application
#include "CTDMADevice.h"

//-------------------------------------------------------------------------------------------------

// Uncomment this to see debug logs
// #define TDMA_DEBUG

#ifdef TDMA_DEBUG
#define CONSOLE_DEBUG(a)	qDebug() << a;
#else
#define CONSOLE_DEBUG(a)
#endif

//-------------------------------------------------------------------------------------------------

PTDMASlot CTDMADevice::s_ucBadSlot		= 0;
PTDMASlot CTDMADevice::s_ucFirstSlot	= 1;
PTDMASlot CTDMADevice::s_ucLastSlot		= 250;

//-------------------------------------------------------------------------------------------------

/*!
    \class CTDMADevice
    \inmodule qt-plus
    \brief A Time Division for Multiple Access class. Can input/output from any QIODevice. Allows
    many devices to transfer data on a single communication channel.

    \section1 Introduction
    This class is a form of Time Division for Multiple Access implementation. \br
    It assumes that many devices will share the same communication channel to exchange data. \br
    It standard TDMA, each device knows when it can send data. The master device synchronizes all
    clocks. \br
    This class does not function with a clock synchronization but with sync messages coming from the
    master device. There is of course more overhead and thus lag than in a clock synchronized system,
    but it avoids this synchronizing phase and is sufficient for systems that are not time critical.

    \section1 How it works
    In a network, one instance of this class acts as master. All other instances are slaves. \br
    At regular intervals, the master sends a message which enables a slave to register itself on
    the network. Of course, many slaves can do this at the same time, causing jam. In this case,
    the master sends a signal to the slaves so that they reset a random timer. Hopefully, only one
    slave will speak the next time the master sends the register message (named aAnyone here). \br
    When the master receives a register demand, it allocates a slot to the slave. The slave is given
    its slot and acknowledges. \br
    The rest of the time, the master sends its own data and a speak message for each slave in turn.
    The slave whose slot corresponds then sends its data. \br\br

    Below is an example of what can happen along a time line.

    \code
    Master     Msg Anyone                 Msg reset   Msg Anyone            Msg SetSlot

    ---------------|-------------|----JAM-----|-----------|----------|-----------|-----------|-------->
    Slave 1                 Resp Anyone                          Resp Anyone             Resp SetSlot
    Slave 2                 Resp Anyone

    Master     Msg Speak                  Msg Anyone             Msg SetSlot             Msg Speak
                Slot 1                                                                     Slot 1
    >--------------|-------------|------------|-----------|----------|-----------|-----------|-------->
    Slave 1                  Resp speak
    Slave 2                                           Resp Anyone            Resp SetSlot

    Master                  Msg Speak                Msg Anyone             Msg Speak
                              Slot 2                                          Slot 1
    >--------------|-------------|------------|-----------|----------------------|-----------|-------->
    Slave 1    Resp speak                                                                Resp speak
    Slave 2                               Resp speak
    \endcode

    \section1 What it does not
    The class does not provide any messaging protocol. The format of the payload is the reponsibility of the user
    of this class. It acts like a socket in a TCP network. \br
    When the master sends data, all slaves receive it. It is up to the user of the class to properly process data
    on slave side (i.e. who is the real recipient of the message, ...)

    \section1 How to use it as a master
    \list
        \li Instantiate the class using a \c QIODevice as your data input and output provider (your physical device).
        Set the \c bIsMaster flag to \c true. The serial number is not important for masters, it may be 0.
        \li Process incoming data from slaves using readFromSerial() and send outgoing data, which is received by all slaves.
    \endlist

    \section1 How to use it as a slave
    The slaves send data to the master and process data that comes from the master. \br
    Note that without a master in the network, nothing will happen.
    \list
        \li Instantiate the class using a \c QIODevice as your data input and output provider (your physical device).
        Set the \c bIsMaster flag to \c false. Provide a unique serial number.
        \li Read and write data using the classic \c QIODevice methods.
        \li If you need to power on an antenna, do this in the \c powerOn() method and return the estimated time for
        power on in milliseconds. And if you need to power off an antenna, do this in the \c powerOff() method.
    \endlist
*/

/*!
    \enum CTDMADevice::EAction
    The first byte of a transmission, indicating the type of action and how to read the following bytes.

    \value aMasterSpeak
    The master device sends its payload.

    \value aSlaveSpeak
    A slave device is ordered to send its payload.

    \value aSlaveSpeakResponse
    A slave device sends its payload.

    \value aSetSlot
    The master device assigns a slot to a slave device.

    \value aSetSlotResponse
    A slave device acknowledges its slot.

    \value aAnyone
    The master device asks any unregistered device to indentify itself.

    \value aAnyoneResponse
    A slave device answers the aAnyone message and identifies itself.

    \value aReset
    The master device orders slave devices to randomly compute a frame offset before answering to aAnyone.
    A simple solution against jamming.
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
    : m_bIsMaster(bIsMaster)
    , m_bAntennaPowered(false)
    , m_tSeriaNumber(tSeriaNumber)
    , m_tSlot(s_ucBadSlot)
    , m_iMaxBytesPerSecond(iMaxBytesPerSecond)
    , m_iMaxBytesPerSlot(4)
    , m_iNumFramesBeforeIdent(0)
    , m_pDevice(pDevice)
    , m_tTimer(this)
    , m_tLastInputTime(now())
    , m_tLastSpeakTime(now())
    , m_tPowerOnTime(now())
{
    static bool bSrandInit = false;

    if (bSrandInit == false)
    {
        bSrandInit = true;

        // Initialize random numbers
        qsrand(now().toTime_t());
    }

    // Connect to IO device
    connect(m_pDevice, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    connect(&m_tTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    connect(&m_tMaintenanceTimer, SIGNAL(timeout()), this, SLOT(onMaintenanceTimeout()));

    if (m_bIsMaster)
    {
        m_tTimer.setInterval(10);
        m_tMaintenanceTimer.setInterval(2000);
        m_tMaintenanceTimer.start();
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
    Sets the serial number of this entity to \a tSerialNumber.
*/
void CTDMADevice::setSerialNumber(PTDMASerial tSerialNumber)
{
    m_tSeriaNumber = tSerialNumber;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the serial number of this entity.
*/
PTDMASerial CTDMADevice::serialNumber() const
{
    return m_tSeriaNumber;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns all serial numbers that are registered in this entity.
*/
QVector<PTDMASerial> CTDMADevice::getAllUserSerialNumbers() const
{
    QVector<PTDMASerial> vSerials;

    for (const CClient& client : m_mRegisteredUsers)
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

    for (PTDMASlot ucSlot : m_mRegisteredUsers.keys())
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
    Returns the current date time.
*/
QDateTime CTDMADevice::now() const
{
    return QDateTime::currentDateTime();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns available bytes to read from the device with \a uiSerialNumber.
*/
qint64 CTDMADevice::bytesAvailableFromSerial(quint16 uiSerialNumber)
{
    for (PTDMASlot ucSlot : m_mRegisteredUsers.keys())
    {
        if (m_mRegisteredUsers[ucSlot].m_tSerialNumber == uiSerialNumber)
        {
            return m_mRegisteredUsers[ucSlot].m_baData.count();
        }
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns data read for the entity identified by \a uiSerialNumber.
*/
QByteArray CTDMADevice::readFromSerial(quint16 uiSerialNumber)
{
    for (PTDMASlot ucSlot : m_mRegisteredUsers.keys())
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

/*!
    Master and slave timed processing.
*/
void CTDMADevice::onTimeout()
{
    if (m_bIsMaster)
    {
        if (m_tLastInputTime.msecsTo(now()) > 50)
        {
            m_tLastInputTime = now();

            sendSpeak();
        }
    }
    else
    {
        if (m_tLastSpeakTime.secsTo(now()) > 3)
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

/*!
    Master only timed processing.
*/
void CTDMADevice::onMaintenanceTimeout()
{
    if (m_bIsMaster)
    {
        for (PTDMASlot slot : m_mRegisteredUsers.keys())
        {
            qint64 iSeconds = m_mRegisteredUsers[slot].m_tLastSpeakTime.secsTo(now());

            if (iSeconds > 10)
            {
                CONSOLE_DEBUG(QString("Kicking slot %1").arg(slot));

                m_mRegisteredUsers.remove(slot);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles the readyRead() signal of the target device.
*/
void CTDMADevice::onReadyRead()
{
    m_tLastInputTime = now();

    m_baRawInput.append(m_pDevice->read(256));

    if (m_baRawInput.count() > 0)
    {
        // CONSOLE_DEBUG(QString("%1 has %2 bytes to process").arg(m_tSeriaNumber).arg(m_baRawInput.count()));

        int iBytesUsed = processInput(m_baRawInput);

        if (iBytesUsed == -1)
        {
            m_baRawInput.clear();
        }

        m_baRawInput = m_baRawInput.mid(iBytesUsed);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Called by onReadyRead() to process incoming \a baData based on the \c m_bIsMaster flag.
*/
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
}

//-------------------------------------------------------------------------------------------------

/*!
    Called by processInput() to process incoming \a baData in master mode.
*/
int CTDMADevice::processInput_Master(const QByteArray& baData)
{
    PTDMAAction ucAction = PTDMAAction(baData[0]);

    switch (ucAction)
    {
        case aSlaveSpeakResponse:
        {
            const TSlaveData_SlaveSpeak* pSpeak = reinterpret_cast<const TSlaveData_SlaveSpeak*>(baData.constData());

            handleSlaveSpeak_Master(pSpeak, baData.mid(sizeof(TSlaveData_SlaveSpeak)));

            return sizeof(TSlaveData_SlaveSpeak) + pSpeak->ucNumBytes;
        }

        case aSetSlotResponse:
        {
            const TSlaveData_SetSlot* pSetSlot = reinterpret_cast<const TSlaveData_SetSlot*>(baData.constData());

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

        case aAnyoneResponse:
        {
            const TSlaveData_Anyone* pAnyone = reinterpret_cast<const TSlaveData_Anyone*>(baData.constData());

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
    }

    return -1;
}

//-------------------------------------------------------------------------------------------------

/*!
    Called by processInput() to process incoming \a baData in slave mode.
*/
int CTDMADevice::processInput_Slave(const QByteArray& baData)
{
    PTDMAAction ucAction = PTDMAAction(baData[0]);

    switch (ucAction)
    {
        // Raw incoming data
        case aMasterSpeak:
        {
            const TMasterData_MasterSpeak* pSpeak = reinterpret_cast<const TMasterData_MasterSpeak*>(baData.constData());

            handleMasterSpeak_Slave(pSpeak, baData.mid(sizeof(TMasterData_MasterSpeak)));

            return sizeof(TMasterData_MasterSpeak) + pSpeak->ucNumBytes;
        }

        // Raw outgoing data
        case aSlaveSpeak:
        {
            const TMasterData_SlaveSpeak* pSpeak = reinterpret_cast<const TMasterData_SlaveSpeak*>(baData.constData());

            handleSpeak_Slave(pSpeak);

            return sizeof(TMasterData_SlaveSpeak);
        }

        // Raw data form a slave
        case aSlaveSpeakResponse:
        {
            const TSlaveData_SlaveSpeak* pSpeak = reinterpret_cast<const TSlaveData_SlaveSpeak*>(baData.constData());

            return sizeof(TSlaveData_SlaveSpeak) + pSpeak->ucNumBytes;
        }

        // Slot assignment
        case aSetSlot:
        {
            const TMasterData_SetSlot* pSetSlot = reinterpret_cast<const TMasterData_SetSlot*>(baData.constData());

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

        // A slave acknowledging a slot
        case aSetSlotResponse:
        {
            const TSlaveData_SetSlot* pSetSlot = reinterpret_cast<const TSlaveData_SetSlot*>(baData.constData());

            return sizeof(TSlaveData_SetSlot);
        }

        // Anyone here?
        case aAnyone:
        {
            handleAnyone_Slave();

            return 1;
        }

        // Response to "anyone here?"
        case aAnyoneResponse:
        {
            const TSlaveData_Anyone* pAnyone = reinterpret_cast<const TSlaveData_Anyone*>(baData.constData());

            return sizeof(TSlaveData_Anyone);
        }

        // Everyone will talk in turn...
        case aReset:
        {
            handleReset_Slave();

            return 1;
        }
    }

    return -1;
}

//-------------------------------------------------------------------------------------------------

/*!
    Processes the TSlaveData_SlaveSpeak message in master mode. \br\br
    \a pSpeak contains the message header \br
    \a baData contains the payload
*/
void CTDMADevice::handleSlaveSpeak_Master(const TSlaveData_SlaveSpeak* pSpeak, const QByteArray& baData)
{
    Q_UNUSED(pSpeak);

    CONSOLE_DEBUG(QString("Master receiving data from slot %1").arg(m_tSlot));
    CONSOLE_DEBUG("... " << baData);

    // Read data from the current slave (m_ucSlot)
    if (m_mRegisteredUsers.contains(m_tSlot))
    {
        m_mRegisteredUsers[m_tSlot].m_baData.append(baData);
        m_mRegisteredUsers[m_tSlot].m_tLastSpeakTime = now();
        m_mRegisteredUsers[m_tSlot].incScore();
    }

    // On envoie le signal de données arrivées
    emit readyRead();

    sendSpeak();
}

//-------------------------------------------------------------------------------------------------

/*!
    Processes the TMasterData_MasterSpeak message in slave mode. \br\br
    \a pSpeak contains the message header \br
    \a baData contains the payload
*/
void CTDMADevice::handleMasterSpeak_Slave(const TMasterData_MasterSpeak* pSpeak, const QByteArray& baData)
{
    Q_UNUSED(pSpeak);

    CONSOLE_DEBUG(QString("Slave receiving data from slot %1").arg(m_tSlot));
    CONSOLE_DEBUG("... " << baData);

    m_baInput.append(baData);
    m_tLastSpeakTime = now();

    // On envoie le signal de données arrivées
    emit readyRead();
}

//-------------------------------------------------------------------------------------------------

/*!
    Processes the handleNewUser_Master message in master mode. \br\br
    \a pAnyone contains the message header
*/
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

/*!
    Processes the handleSetSlot_Master message in master mode. \br\br
    \a pSetSlot contains the message header
*/
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

/*!
    Processes the handleSpeak_Master message in master mode.
*/
void CTDMADevice::handleSpeak_Master()
{
    if (m_baOutput.count() > 0)
    {
        QByteArray baOut = m_baOutput.left(m_iMaxBytesPerSlot);
        m_baOutput = m_baOutput.mid(baOut.count());

        TMasterData_MasterSpeak tSpeak;

        tSpeak.ucAction = aMasterSpeak;
        tSpeak.ucNumBytes = baOut.count();

        m_pDevice->write(reinterpret_cast<const char*>(&tSpeak), sizeof(TMasterData_MasterSpeak));
        m_pDevice->write(baOut);

        m_tLastSpeakTime = now();
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Processes the handleSpeak_Slave message in slave mode. \br\br
    \a pSpeak contains the message header
*/
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

            m_pDevice->write(reinterpret_cast<const char*>(&tSpeak), sizeof(TSlaveData_SlaveSpeak));
            m_pDevice->write(baOut);

            m_tLastSpeakTime = now();
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Processes the handleSetSlot_Slave message in slave mode. \br\br
    \a pSetSlot contains the message header
*/
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

        m_pDevice->write(reinterpret_cast<const char*>(&tAnswer), sizeof(TSlaveData_SetSlot));

        m_tLastSpeakTime = now();
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Processes the aAnyone action in slave mode.
*/
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

            m_pDevice->write(reinterpret_cast<const char*>(&tAnswer), sizeof(TSlaveData_Anyone));

            m_tLastSpeakTime = now();
        }
        else
        {
            m_iNumFramesBeforeIdent--;
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Processes the aReset action in slave mode.
*/
void CTDMADevice::handleReset_Slave()
{
    if (m_tSlot == s_ucBadSlot && m_iNumFramesBeforeIdent == 0)
    {
        m_iNumFramesBeforeIdent = 1 + (qrand() % 10);

        CONSOLE_DEBUG(QString("Slave %1 sets m_iNumFramesBeforeIdent to %2").arg(m_tSeriaNumber).arg(m_iNumFramesBeforeIdent));
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Called in master mode to order slaves to speak.
*/
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
            if (m_mRegisteredUsers.contains(m_tSlot))
            {
                qint64 iDifference = m_mRegisteredUsers[m_tSlot].m_tLastOrderSpeakTime.msecsTo(now());

                if (m_mRegisteredUsers[m_tSlot].m_iScore > 0 || iDifference > 1000)
                {
                    CONSOLE_DEBUG("Master sending aSlaveSpeak for slot " << m_tSlot);

                    TMasterData_SlaveSpeak tSpeak;
                    tSpeak.ucAction = aSlaveSpeak;
                    tSpeak.ucSlot = m_tSlot;

                    m_mRegisteredUsers[m_tSlot].decScore();
                    m_mRegisteredUsers[m_tSlot].m_tLastOrderSpeakTime = now();
                    m_pDevice->write(reinterpret_cast<const char *>(&tSpeak), sizeof(TMasterData_SlaveSpeak));
                }
            }
        }
    }
    else
    {
        m_tSlot = s_ucBadSlot;

        sendSetSlot();
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Called in master mode to speak and assign slots.
*/
void CTDMADevice::sendSetSlot()
{
    if (m_baOutput.count() > 0)
    {
        CONSOLE_DEBUG("Master speaking");

        handleSpeak_Master();
    }
    else
    {
        if (m_vNewUsers.count() > 0)
        {
            CONSOLE_DEBUG("Master sending SetSlot for " << QString::number(m_vNewUsers[0].m_tSerialNumber) << " : " << QString::number(m_vNewUsers[0].m_tSlot));

            TMasterData_SetSlot tSetSlot;

            tSetSlot.ucAction = aSetSlot;
            tSetSlot.uiSerialNumber = m_vNewUsers[0].m_tSerialNumber;
            tSetSlot.ucSlot = m_vNewUsers[0].m_tSlot;
            tSetSlot.ucMaxBytesPerSlot = m_iMaxBytesPerSlot;
            tSetSlot.ucActionEcho = aSetSlot;

            m_pDevice->write(reinterpret_cast<const char*>(&tSetSlot), sizeof(TMasterData_SetSlot));
        }
        else
        {
            sendAnyone();
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Called in master mode to send the aAnyone action.
*/
void CTDMADevice::sendAnyone()
{
    // CONSOLE_DEBUG("Master sending Anyone");

    m_pDevice->write(QByteArray(1, aAnyone));
}

//-------------------------------------------------------------------------------------------------

/*!
    Called in master mode to send the aReset action.
*/
void CTDMADevice::sendReset()
{
    CONSOLE_DEBUG("Master sending Reset");

    m_pDevice->write(QByteArray(1, aReset));
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a free slot number or s_ucBadSlot if none available.
*/
PTDMASlot CTDMADevice::getFreeSlot() const
{
    for (PTDMASlot ucIndex = s_ucFirstSlot; ucIndex <= s_ucLastSlot; ucIndex++)
    {
        bool bUsed = false;

        for (const CClient& tClient : m_vNewUsers)
        {
            if (tClient.m_tSlot == ucIndex)
            {
                bUsed = true;
                break;
            }
        }

        if (bUsed == false)
        {
            for (PTDMASlot ucSlot : m_mRegisteredUsers.keys())
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

/*!
    Implements the readData() virtual method of QIODevice. \br\br
    \a data is a pointer to fill \br
    \a maxSize is the number of bytes to read
*/
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

/*!
    Implements the writeData() virtual method of QIODevice. \br\br
    \a data is a pointer to read from \br
    \a maxSize is the number of bytes to write
*/
qint64 CTDMADevice::writeData(const char* pData, qint64 iSize)
{
    m_baOutput.append(QByteArray(pData, int(iSize)));

    if (m_bAntennaPowered == false)
    {
        m_bAntennaPowered = true;
        m_tLastSpeakTime = m_tPowerOnTime = now();

        // int iPowerOnMS = powerOn();
    }

    return iSize;
}
