
// Qt
#include <QDebug>
#include <QDateTime>

// Application
#include "ROKE.h"

//-------------------------------------------------------------------------------------------------

#define LOG_DEBUG(a)
// #define LOG_DEBUG(a) qDebug() << (a);

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
//    QByteArray baData = QByteArray::fromBase64(sText.toLatin1());
//    QByteArray baResult = decrypt(baData);
//    return QString::fromUtf8(baResult);

    return sText;
}

//-------------------------------------------------------------------------------------------------

QByteArray ROKE::encrypt(const QByteArray& baData)
{
    QByteArray baResult;

    quint32 uiMaskIndex = 0;

    for (int index = 0; index < baData.count(); index++)
    {
        quint8 uiData = baData[index];
        uiData ^= m_vKeyMasks[m_vKeyOrders[uiMaskIndex]];
        baResult.append((char) uiData);

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

void ROKE::decodeKey()
{
    LOG_DEBUG("ROKE::decodeKey()");

    LOG_DEBUG(QString("Test 1000 : %1").arg(reverseBits32(reverseBits32(1000))));

    return;

    QString sRealKey = QString(reverseArray(m_sKey.toLatin1()));

    m_vKeyOrders.clear();
    m_vKeyMasks.clear();

    quint32 uiKeySizeFieldSize = sizeof(quint32);
    QString sKeySize = sRealKey.mid(0, uiKeySizeFieldSize);
    m_uiKeySize = reverseBits32(sKeySize.toUInt(nullptr, 16));

    quint32 uiKeyMasksFieldSize = sizeof(quint8) * m_uiKeySize;
    QString sKeyMasks = sRealKey.mid(uiKeySizeFieldSize, uiKeyMasksFieldSize * 2);

    for (quint32 index = 0; index < m_uiKeySize; index++)
    {
        m_vKeyMasks << sKeyMasks.mid(index, sizeof(quint8)).toUInt(nullptr, 16);
        m_vKeyOrders << sKeyMasks.mid(index, sizeof(quint8)).toUInt(nullptr, 16);
    }

    LOG_DEBUG(QString("... masks : %1 %2").arg(m_vKeyMasks[0]).arg(m_vKeyMasks[1]));
    LOG_DEBUG(QString("... orders : %1 %2").arg(m_vKeyOrders[0]).arg(m_vKeyOrders[1]));
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
    quint32 index;

    // Generate order bytes
    for (index = 0; index < uiKeySize; index++)
    {
        lKeyOrders << index;
    }

    shuffle(lKeyOrders, uiKeySize * 2);

    // Generate masks
    for (index = 0; index < uiKeySize; index++)
    {
        lKeyMasks << (quint8) (randomInt32() & 0xFF);
    }

    LOG_DEBUG(QString("... masks : %1 %2").arg(lKeyMasks[0]).arg(lKeyMasks[1]));
    LOG_DEBUG(QString("... orders : %1 %2").arg(lKeyOrders[0]).arg(lKeyOrders[1]));

    // Output key data

    sReturnValue += QString("%1").arg(reverseBits32(uiKeySize), sizeof(quint32), 16, QChar('0'));

    for (index = 0; index < uiKeySize; index++)
    {
        sReturnValue += QString("%1").arg(lKeyMasks[index], sizeof(quint8), 16, QChar('0'));
        sReturnValue += QString("%1").arg(lKeyOrders[index], sizeof(quint8), 16, QChar('0'));
    }

    return QString(reverseArray(sReturnValue.toLatin1()));
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
    qsrand(QDateTime::currentDateTime().toTime_t());

    quint32 uiPart1 = qrand() & 0xFFFF;
    quint32 uiPart2 = qrand() & 0xFFFF;

    return uiPart1 | (uiPart2 << 16);
}

//-------------------------------------------------------------------------------------------------

quint32 ROKE::reverseBits32(quint32 n)
{
    // return ((x * 0x0802 & 0x22110) | (x * 0x8020 & 0x88440)) * 0x10101 >> 16;

    quint32 x;

    for(auto i = 31; n; ) {
        x |= (n & 1) << i;
        n >>= 1;
        -- i;
    }

    return x;
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
