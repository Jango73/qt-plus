
// Application
#include "CWebContext.h"

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext()
    : m_pSocket(nullptr)
    , m_pSession(nullptr)
{
}

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext(
        QTcpSocket* pSocket,
        QMap<QString, QVariant> mUserData,
        CWebSession* pSession
        )
    : m_pSocket(pSocket)
    , m_pSession(pSession)
    , m_mUserData(mUserData)
{
    SAFE_USE(pSocket)
    {
        m_sPeer = cleanIP(m_pSocket->peerAddress().toString());
    }
}

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext(const CWebContext& target)
    : m_pSocket(target.m_pSocket)
    , m_pSession(target.m_pSession)
    , m_sPeer(target.m_sPeer)
    , m_sHost(target.m_sHost)
    , m_lPath(target.m_lPath)
    , m_mArguments(target.m_mArguments)
    , m_mArgumentMIMEs(target.m_mArgumentMIMEs)
    , m_mUserData(target.m_mUserData)
    , m_sContentType(target.m_sContentType)
    , m_baPostContent(target.m_baPostContent)
{
}

//-------------------------------------------------------------------------------------------------

CWebContext::~CWebContext()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the IP address in \a sText stripped out of any garbage
*/
QString CWebContext::cleanIP(const QString& sText)
{
    QString sReturnValue = sText;
    QRegExp tRegExp_ipv6("([A-Fa-f0-9]{1,4}::?){1,7}[A-Fa-f0-9]{1,4}");
    QRegExp tRegExp_ipv4(".*([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}).*");

    if (tRegExp_ipv6.indexIn(sText) != -1)
    {
        sReturnValue = tRegExp_ipv6.cap(0);
    }
    else if (tRegExp_ipv4.indexIn(sText) != -1)
    {
        sReturnValue = tRegExp_ipv4.cap(1);
    }

    return sReturnValue;
}
