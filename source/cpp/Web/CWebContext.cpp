
// Application
#include "CWebContext.h"
#include <QRegularExpression>

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

CWebContext::CWebContext(
        QTcpSocket* pSocket,
        QString sPeer,
        QString sHost
        )
    : m_pSocket(pSocket)
    , m_pSession(nullptr)
    , m_sPeer(sPeer)
    , m_sHost(sHost)
{
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
    QRegularExpression tRegExp_ipv6("([A-Fa-f0-9]{1,4}::?){1,7}[A-Fa-f0-9]{1,4}");
    QRegularExpression tRegExp_ipv4(".*([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}).*");

    QRegularExpressionMatch match_ipv6 = tRegExp_ipv6.match(sText);
    if (match_ipv6.hasMatch())
    {
        sReturnValue = match_ipv6.captured(0);
    }
    else
    {
        QRegularExpressionMatch match_ipv4 = tRegExp_ipv4.match(sText);
        if (match_ipv4.hasMatch())
        {
            sReturnValue = match_ipv4.captured(1);
        }
    }

    return sReturnValue;
}
