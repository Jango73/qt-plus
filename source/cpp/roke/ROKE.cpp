
// Qt
#include <QDebug>
#include <QDateTime>

// Application
#include "ROKE.h"

//-------------------------------------------------------------------------------------------------

#define LOG_DEBUG(a)
// #define LOG_DEBUG(a) qDebug() << (a);

#define HEX_BYTE_SIZE (sizeof(quint8) * 2)

bool ROKE::s_bSeedInit = false;

//-------------------------------------------------------------------------------------------------

ROKE::ROKE()
    : m_uiKeySize(0)
{
}

//-------------------------------------------------------------------------------------------------

ROKE::ROKE(const QString& sKey)
    : m_sKey(sKey)
    , m_uiKeySize(0)
{
    decodeKey();
}

//-------------------------------------------------------------------------------------------------

ROKE::~ROKE()
{
}

//-------------------------------------------------------------------------------------------------

void ROKE::setKey(const QString& sKey)
{
    m_sKey = sKey;

    decodeKey();

//    test();
}

//-------------------------------------------------------------------------------------------------

QString ROKE::key() const
{
    return m_sKey;
}

//-------------------------------------------------------------------------------------------------

QString ROKE::encryptString(const QString& sText)
{
    QByteArray baData = sText.toUtf8();
    QByteArray baResult = encrypt(baData);
    QString sResult(baResult.toBase64());
    return sResult;
}

//-------------------------------------------------------------------------------------------------

QString ROKE::decryptString(const QString& sText)
{
    QByteArray baData = QByteArray::fromBase64(sText.toLatin1());
    QByteArray baResult = decrypt(baData);
    return QString::fromUtf8(baResult);
}

//-------------------------------------------------------------------------------------------------

QByteArray ROKE::encrypt(const QByteArray& baData)
{
    QByteArray baResult;

    quint32 uiMaskIndex = 0;

    for (int index = 0; index < baData.count(); index++)
    {
        char cData = baData[index];
        quint8 uiData = *((quint8*)&cData);
        uiData ^= m_vKeyMasks[m_vKeyOrders[uiMaskIndex]];
        *((quint8*)&cData) = uiData;
        baResult.append(cData);

        uiMaskIndex++;
        if (uiMaskIndex >= m_uiKeySize)
            uiMaskIndex = 0;
    }

    return baResult;
}

//-------------------------------------------------------------------------------------------------

QByteArray ROKE::decrypt(const QByteArray& baData)
{
    return encrypt(baData);
}

//-------------------------------------------------------------------------------------------------

QString ROKE::generateKey(QString sMetaData)
{
    Q_UNUSED(sMetaData);

    LOG_DEBUG("ROKE::generateKey()");

    QString sReturnValue;
    quint32 uiKeySize = 32 + randomInt32() % 32;
    QVector<quint8> lKeyOrders;
    QVector<quint8> lKeyMasks;

    LOG_DEBUG(QString("... key size : %1").arg(uiKeySize));

    // Generate order bytes
    for (quint32 index = 0; index < uiKeySize; index++)
    {
        lKeyOrders << index;
    }

    shuffle(lKeyOrders, uiKeySize * 2);

    // Generate masks
    for (quint32 index = 0; index < uiKeySize; index++)
    {
        lKeyMasks << (quint8) (randomInt32() & 0xFF);
    }

    // Output key data

    LOG_DEBUG("... Masks and orders");

    sReturnValue += QString("%1").arg(reverseBits32(uiKeySize), sizeof(quint32) * HEX_BYTE_SIZE, 16, QChar('0'));

    for (quint32 index = 0; index < uiKeySize; index++)
    {
        sReturnValue += QString("%1").arg(lKeyMasks[index], sizeof(quint8) * HEX_BYTE_SIZE, 16, QChar('0'));
        sReturnValue += QString("%1").arg(lKeyOrders[index], sizeof(quint8) * HEX_BYTE_SIZE, 16, QChar('0'));

        LOG_DEBUG(QString("... %1, %2").arg(lKeyMasks[index]).arg(lKeyOrders[index]));
    }

    LOG_DEBUG(QString("... key : %1").arg(sReturnValue));

    return QString(reverseArray(sReturnValue.toLatin1()));
}

//-------------------------------------------------------------------------------------------------

void ROKE::decodeKey()
{
    LOG_DEBUG("ROKE::decodeKey()");

    QString sRealKey = QString(reverseArray(m_sKey.toLatin1()));

    m_vKeyOrders.clear();
    m_vKeyMasks.clear();

    quint32 uiKeySizeFieldSize = sizeof(quint32) * HEX_BYTE_SIZE;
    QString sKeySize = sRealKey.mid(0, uiKeySizeFieldSize);

    m_uiKeySize = reverseBits32(sKeySize.toUInt(nullptr, 16));

    LOG_DEBUG(QString("... key size : %1").arg(m_uiKeySize));

    quint32 uiKeyMasksFieldSize = HEX_BYTE_SIZE * m_uiKeySize;
    QString sKeyMasks = sRealKey.mid(uiKeySizeFieldSize, uiKeyMasksFieldSize * 2);

    LOG_DEBUG("... Masks and orders");

    for (quint32 index = 0; index < m_uiKeySize; index++)
    {
        quint32 iMask = index * (HEX_BYTE_SIZE * 2);
        quint32 iOrder = iMask + HEX_BYTE_SIZE;

        m_vKeyMasks << sKeyMasks.mid(iMask, HEX_BYTE_SIZE).toUInt(nullptr, 16);
        m_vKeyOrders << sKeyMasks.mid(iOrder, HEX_BYTE_SIZE).toUInt(nullptr, 16);

        LOG_DEBUG(QString("... %1, %2").arg(m_vKeyMasks[index]).arg(m_vKeyOrders[index]));
    }
}

//-------------------------------------------------------------------------------------------------

void ROKE::shuffle(QVector<quint8>& vValues, int iIterations)
{
    for (int index = 0; index < iIterations; index++)
    {
        int iIndex1 = qrand() % vValues.count();
        int iIndex2 = qrand() % vValues.count();

        if (iIndex1 != iIndex2)
        {
            quint8 uiTemp = vValues[iIndex1];
            vValues[iIndex1] = vValues[iIndex2];
            vValues[iIndex2] = uiTemp;
        }
    }
}

//-------------------------------------------------------------------------------------------------

quint32 ROKE::randomInt32()
{
    if (s_bSeedInit == false)
    {
        qsrand(QDateTime::currentDateTime().toTime_t());
        s_bSeedInit = true;
    }

    quint32 uiPart1 = qrand() & 0xFFFF;
    quint32 uiPart2 = qrand() & 0xFFFF;

    return uiPart1 | (uiPart2 << 16);
}

//-------------------------------------------------------------------------------------------------

quint32 ROKE::reverseBits32(quint32 n)
{
    return n;

    // TODO : Find a working method

//    return ((n * 0x0802 & 0x22110) | (n * 0x8020 & 0x88440)) * 0x10101 >> 16;

//    quint32 x;

//    for(auto i = 31; n; ) {
//        x |= (n & 1) << i;
//        n >>= 1;
//        -- i;
//    }

//    return x;
}

//-------------------------------------------------------------------------------------------------

QByteArray ROKE::reverseArray(const QByteArray& seq)
{
    QByteArray reverse;

    for (QByteArray::const_iterator i = seq.constEnd(); i !=seq.constBegin();)
    {
        --i;
        reverse += (*i);
    }

    return reverse;
}

//-------------------------------------------------------------------------------------------------

void ROKE::test()
{
    quint32 uiData = 1000;
    uiData = reverseBits32(uiData);
    uiData = reverseBits32(uiData);

    qDebug() << QString("reverseBits32(1000) : %1").arg(uiData);

    ROKE tROKE(ROKE::generateKey());

    QString sText = "The original text";

    qDebug() << QString("Original : %1").arg(sText);

    QByteArray baData = tROKE.encrypt(sText.toLatin1());
    qDebug() << QString("Encrypted : %1").arg(QString(baData));

    sText = QString(tROKE.decrypt(baData));
    qDebug() << QString("Decrypted : %1").arg(sText);
}
