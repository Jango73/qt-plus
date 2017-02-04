
// Application
#include "CWebContext.h"

//-------------------------------------------------------------------------------------------------

CWebContext::CWebContext()
    : m_pSocket(NULL)
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

CWebContext::~CWebContext()
{
}
