
// Qt
#include <QThread>

// qt-plus
#include "CLogger.h"

// Application
#include "CTracableMutex.h"

QMap<int, QString> CTracableMutex::m_vThreadNames;



CTracableMutex::CTracableMutex(QString sName)
    : m_tMutex()
    , m_sName(sName)
{
}

CTracableMutex::~CTracableMutex()
{
}

void CTracableMutex::registerThread(int iThreadID, QString sName)
{
#ifdef FULL_MUTEX_TRACE
    if (m_vThreadNames.contains(iThreadID) == false)
    {
        LOG_DEBUG(QString("CTracableMutex::registerThread() : adding thread %1 (%2)").arg(sName).arg(iThreadID));
        m_vThreadNames[iThreadID] = sName;
    }
#endif
}

bool CTracableMutex::lock(QString sName)
{
    QDateTime tTime(QDateTime::currentDateTime());

    // Block until the mutex is actually acquired. Returning false without
    // holding the lock would leave the critical section unprotected for any
    // caller ignoring the return value, so lock() only returns when held.
    while (!m_tMutex.tryLock(5000))
    {
        int iThreadID = (int) ((qlonglong) QThread::currentThreadId());
        QString sThread = QString::number(iThreadID);

#ifdef FULL_MUTEX_TRACE
        if (m_vThreadNames.contains(iThreadID))
        {
            sThread = m_vThreadNames[iThreadID];
        }

        if (sName == "")
        {
            sName = "<UNKNOWN>";
        }
#endif

        LOG_CRITICAL("-----------------------------------------------------------------------");
        LOG_CRITICAL(QString("Mutex %1 lock timeout ! in thread %2 (retrying)").arg(m_sName).arg(sThread));

#ifdef FULL_MUTEX_TRACE
        for (QString sLockName : m_sLockNames)
        {
            LOG_CRITICAL(QString("... locked by %1").arg(sLockName));
        }
#endif

        LOG_CRITICAL("-----------------------------------------------------------------------");
    }

    if (tTime.msecsTo(QDateTime::currentDateTime()) > 1000)
    {
        int iThreadID = (int) ((qlonglong) QThread::currentThreadId());
        QString sThread = QString::number(iThreadID);

#ifdef FULL_MUTEX_TRACE
        if (m_vThreadNames.contains(iThreadID))
        {
            sThread = m_vThreadNames[iThreadID];
        }
#endif

        LOG_WARNING("-----------------------------------------------------------------------");
        LOG_WARNING(QString("Mutex %1 lock time > 1 second in thread %2").arg(m_sName).arg(sThread));

#ifdef FULL_MUTEX_TRACE
        for (QString sLockName : m_sLockNames)
        {
            LOG_WARNING(QString("... locked by %1").arg(sLockName));
        }
#endif

        LOG_WARNING("-----------------------------------------------------------------------");
    }

    return true;
}

void CTracableMutex::unlock()
{
#ifdef FULL_MUTEX_TRACE
    if (m_sLockNames.size())
    {
        m_sLockNames.remove(m_sLockNames.size() - 1);
    }
#endif

    m_tMutex.unlock();
}
