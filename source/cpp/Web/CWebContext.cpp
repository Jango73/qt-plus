
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

CWebContext::CWebContext(
        QTcpSocket* pSocket,
        QString sPeer,
        QString sHost,
        QStringList lPath,
        QMap<QString, QString> mArguments,
        QMap<QString, QVariant> mUserData
        )
    : m_pSocket(pSocket)
    , m_sPeer(sPeer)
    , m_sHost(sHost)
    , m_lPath(lPath)
    , m_mArguments(mArguments)
    , m_mUserData(mUserData)
{
}

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext(const CWebContext& target)
    : m_pSocket(target.m_pSocket)
    , m_sPeer(target.m_sPeer)
    , m_sHost(target.m_sHost)
    , m_lPath(target.m_lPath)
    , m_mArguments(target.m_mArguments)
    , m_mUserData(target.m_mUserData)
    , m_baPostContent(target.m_baPostContent)
{
}

//-------------------------------------------------------------------------------------------------

CWebContext::~CWebContext()
{
}
