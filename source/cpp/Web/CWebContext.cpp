
// Application
#include "CWebContext.h"

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext()
    : m_pSocket(nullptr)
{
}

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext(QTcpSocket* pSocket, QString sPeer, QString sHost, QStringList lPath, QMap<QString, QString> mArguments)
    : m_pSocket(pSocket)
    , m_sPeer(sPeer)
    , m_sHost(sHost)
    , m_lPath(lPath)
    , m_mArguments(mArguments)
{
}

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext(const CWebContext& target)
    : m_pSocket(target.m_pSocket)
    , m_sPeer(target.m_sPeer)
    , m_sHost(target.m_sHost)
    , m_lPath(target.m_lPath)
    , m_mArguments(target.m_mArguments)
    , m_baPostContent(target.m_baPostContent)
{
}

//-------------------------------------------------------------------------------------------------

CWebContext::~CWebContext()
{
}
