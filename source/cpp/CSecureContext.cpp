
// Qt
#include <QTextStream>

// Application
#include "CSecureContext.h"

//-------------------------------------------------------------------------------------------------

#define LOG_DEBUG(a)
// #define LOG_DEBUG(a) echo(QString("DEBUG : %2\n").arg(a))

//-------------------------------------------------------------------------------------------------

CSecureContext::CSecureContext(bool bIsServer)
    : m_pRSAKeys(new KeyPair(RSA::GenerateKeyPair(10)))
    , m_tROKE(ROKE::generateKey())
    , m_bIsServer(bIsServer)
{
    LOG_DEBUG(QString("CSecureContext::CSecureContext(%1)").arg(bIsServer));
    LOG_DEBUG(QString("... ROKE key : %1").arg(m_tROKE.key()));
}

//-------------------------------------------------------------------------------------------------

CSecureContext::~CSecureContext()
{
    if (m_pRSAKeys != nullptr)
        delete m_pRSAKeys;
}

//-------------------------------------------------------------------------------------------------

void CSecureContext::echo(QString sText)
{
    QTextStream stream(stdout);
    stream << sText;
    stream.flush();
}

//-------------------------------------------------------------------------------------------------

void CSecureContext::setContextData(const QByteArray& baContext)
{
    LOG_DEBUG("CSecureContext::setContextData");

    QStringList sKeys = QString(baContext).split(",");

    // Check key count
    if (sKeys.count() == 3)
    {
        LOG_DEBUG(QString("... RSA modulus : %1").arg(sKeys[0]));
        LOG_DEBUG(QString("... RSA exponent : %1").arg(sKeys[1]));
        LOG_DEBUG(QString("... RSA ROKE key : %1").arg(sKeys[2]));

        // Get RSA key components
        BigInt biModulus(sKeys[0].toStdString());
        BigInt biExponent(sKeys[1].toStdString());

        if (m_pRSAKeys != nullptr)
            delete m_pRSAKeys;

        m_pRSAKeys = new KeyPair(Key(BigInt(), BigInt()), Key(biModulus, biExponent));

        // Get the decrypted ROKE key
        QString sROKEKey = QString::fromStdString(
                    RSA::Decrypt(
                        sKeys[2].toStdString(), m_pRSAKeys->GetPublicKey()
                    ));

        LOG_DEBUG(QString("... ROKE key : %1").arg(sROKEKey));

        m_tROKE.setKey(sROKEKey);
    }
    else
    {
        LOG_DEBUG(QString("... Wrong key count"));
    }
}

//-------------------------------------------------------------------------------------------------

QByteArray CSecureContext::contextData() const
{
    QString sROKEKey = m_tROKE.key();

    // Get the RSA keys
    QString sModulus = QString::fromStdString(m_pRSAKeys->GetPublicKey().GetModulus().ToString());
    QString sExponent = QString::fromStdString(m_pRSAKeys->GetPublicKey().GetExponent().ToString());

    // Get the encrypted ROKE key
    QString sROKE = QString::fromStdString(
                RSA::Encrypt(
                    sROKEKey.toStdString(), m_pRSAKeys->GetPrivateKey())
                );

    QString sFinal = QString("%1,%2,%3").arg(sModulus).arg(sExponent).arg(sROKE);

    return sFinal.toLatin1();
}

//-------------------------------------------------------------------------------------------------

QByteArray CSecureContext::encrypt(const QByteArray& baData)
{
    return m_tROKE.encrypt(baData);
}

//-------------------------------------------------------------------------------------------------

QByteArray CSecureContext::decrypt(const QByteArray& baData)
{
    return m_tROKE.decrypt(baData);
}
