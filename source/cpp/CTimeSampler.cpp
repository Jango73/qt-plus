
// Application
#include "CLogger.h"
#include "CTimeSampler.h"

CTimeSampler::CTimeSampler()
    : m_tMutex(QMutex::Recursive)
    , m_tDumpTimer(this)
    , m_pLogger(CLogger::getInstance())
{
    connect(&m_tDumpTimer, SIGNAL(timeout()), this, SLOT(onTimer()));

    m_tDumpTimer.start(10000);
}

CTimeSampler::CTimeSampler(CLogger* pLogger)
    : m_tMutex(QMutex::Recursive)
    , m_tDumpTimer(this)
    , m_pLogger(pLogger)
{
    connect(&m_tDumpTimer, SIGNAL(timeout()), this, SLOT(onTimer()));

    m_tDumpTimer.start(10000);

    if (m_pLogger == nullptr)
    {
        m_pLogger = CLogger::getInstance();
    }
}

CTimeSampler::~CTimeSampler()
{
    m_tDumpTimer.stop();
}

void CTimeSampler::onTimer()
{
    m_tDumpTimer.stop();

    dumpAccumulatedTimes();

    m_tDumpTimer.start();
}

void CTimeSampler::startSample(const QString& sName)
{
    if (m_tMutex.lock())
    {
        m_mStartTimes[sName] = QDateTime::currentDateTime();

        if (m_mAccumTimes.contains(sName) == false)
        {
            m_mAccumTimes[sName] = 0;
            m_mNumCalls[sName] = 0;
        }

        m_mNumCalls[sName]++;

        m_tMutex.unlock();
    }
}

void CTimeSampler::stopSample(const QString& sName)
{
    if (m_mStartTimes.contains(sName))
    {
        if (m_tMutex.lock())
        {
            QDateTime dNow = QDateTime::currentDateTime();
            qint64 msecs = m_mStartTimes[sName].msecsTo(dNow);

            m_mAccumTimes[sName] += msecs;

            m_tMutex.unlock();
        }
    }
}

void CTimeSampler::stopSampleAndLog(const QString& sName)
{
    if (m_mStartTimes.contains(sName))
    {
        if (m_tMutex.lock())
        {
            QDateTime dNow = QDateTime::currentDateTime();
            qint64 msecs = m_mStartTimes[sName].msecsTo(dNow);

            m_mAccumTimes[sName] += msecs;

            m_pLogger->log(llDebug, QString("%1 = %2 milliseconds").arg(sName).arg(msecs), "TimeSample");

            m_tMutex.unlock();
        }
    }
}

void CTimeSampler::dumpAccumulatedTimes()
{
    m_pLogger->log(llDebug, "------------------------------------------------------------", "TimeSample");
    m_pLogger->log(llDebug, "Total accumulated times", "TimeSample");

    for (QString sName : m_mStartTimes.keys())
    {
        double dMillisecs = (double) m_mAccumTimes[sName] / 1000.0;
        double dAverageMsecs = (double) dMillisecs / (double) m_mNumCalls[sName];

        m_pLogger->log(llDebug,
                       QString("  %1 = %2 s (avg %3 s for %4 calls)")
                       .arg(sName)
                       .arg(dMillisecs)
                       .arg(dAverageMsecs)
                       .arg(m_mNumCalls[sName]), "TimeSample"
                       );
    }

    m_pLogger->log(llDebug, "------------------------------------------------------------", "TimeSample");
}
