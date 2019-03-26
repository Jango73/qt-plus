
// Qt
#include <QTextStream>

// Application
#include "CSecureContext.h"

//-------------------------------------------------------------------------------------------------

#define LOG_DEBUG(a)
// #define LOG_DEBUG(a) echo(QString("DEBUG : %2\n").arg(a))

//-------------------------------------------------------------------------------------------------

/*!
    \class CSecureContext
    \inmodule qt-plus
    \brief A context that enables secure data transfer.

    \section1 How to use
    Both server and client must use this context, but in slightly different ways.
    When the server receives a connection:
    \list
        \li Create a CSecureContext by specifying \c true
        \li Associate the context with the connection to the client
        \li Call contextData() and send the returned QByteArray to the client
    \endlist
    When the client receives the QByteArray containing the secure data:
    \list
        \li Create a CSecureContext by specifying \c false
        \li Associate the context with the connection to the server
        \li Call setContextData() with the ByteArray sent by the server
    \endlist
    Now that both sides are ready for secure transfers, we just have to call
    encrypt() just before sending a packet and decrypt() just afert receiving
    one. That's it.

    \section1 How it works
    The actual data encryption is made using ROKE, a home made, rather simple, algorithm which
    uses a key of random size (between 32 and 64 digits). Since the key is symetric, it is
    sent to the client using RSA (64 bit key). It then becomes quite difficult to guess the key.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CSecureContext. \br\br
    \a bIsServer tells if the class behavior is for a server \br
*/
CSecureContext::CSecureContext(bool bIsServer)
    : m_pRSAKeys(new KeyPair(RSA::GenerateKeyPair(16)))
    , m_tROKE(ROKE::generateKey())
    , m_bIsServer(bIsServer)
{
    LOG_DEBUG(QString("CSecureContext::CSecureContext(%1)").arg(bIsServer));
    LOG_DEBUG(QString("... ROKE key : %1").arg(m_tROKE.key()));
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CSecureContext.
*/
CSecureContext::~CSecureContext()
{
    if (m_pRSAKeys != nullptr)
        delete m_pRSAKeys;
}

//-------------------------------------------------------------------------------------------------

/*!
    Echoes text on standard output.
*/
void CSecureContext::echo(QString sText)
{
    QTextStream stream(stdout);
    stream << sText;
    stream.flush();
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the key data from \a baContext.
*/
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

/*!
    Returns the key data.
*/
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

/*!
    Encrypts the data in \a baData.
*/
QByteArray CSecureContext::encrypt(const QByteArray& baData)
{
    return m_tROKE.encrypt(baData);
}

//-------------------------------------------------------------------------------------------------

/*!
    Decrypts the data in \a baData.
*/
QByteArray CSecureContext::decrypt(const QByteArray& baData)
{
    return m_tROKE.decrypt(baData);
}
