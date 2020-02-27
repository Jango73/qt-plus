
// Application
#include "CWebContext.h"

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext()
    : m_pSocket(nullptr)
{
}

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext(
        QTcpSocket* pSocket,
        QMap<QString, QVariant> mUserData
        )
    : m_pSocket(pSocket)
    , m_mUserData(mUserData)
{
}

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext(QTcpSocket* pSocket,
        QString sPeer,
        QString sHost)
    : m_pSocket(pSocket)
    , m_sPeer(sPeer)
    , m_sHost(sHost)
{
}

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext(const CWebContext& target)
    : m_pSocket(target.m_pSocket)
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
