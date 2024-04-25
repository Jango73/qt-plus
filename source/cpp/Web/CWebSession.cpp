
// Qt
#include <QCoreApplication>
#include <QFile>

// Application
#include "CWebSession.h"
#include "CHTTPServer.h"

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebSession
*/
CWebSession::CWebSession(CHTTPServer* pServer)
    : m_mMutex(QMutex::Recursive)
    , m_pServer(pServer)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebSession.
*/
CWebSession::~CWebSession()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if safe access to data is OK (data is locked).
*/
bool CWebSession::lock()
{
    if (m_mMutex.tryLock(2000))
    {
        return true;
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

/*!
    Unlocks access to data.
*/
void CWebSession::unlock()
{
    m_mMutex.unlock();
}
