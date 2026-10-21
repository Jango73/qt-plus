
// Application
#include "CLogger.h"
#include "CTimeSampler.h"

/************************************************************************/

static const int TimeSamplerDumpIntervalMs = 10000;

/************************************************************************/

CTimeSampler::CTimeSampler()
    : m_tMutex()
    , m_tDumpTimer(this)
    , m_dLastFrameMs(0.0)
    , m_iFrameCount(0)
    , m_bFirstFrame(true)
    , m_iDumpIntervalMs(TimeSamplerDumpIntervalMs)
    , m_pLogger(CLogger::getInstance())
{
    connect(&m_tDumpTimer, SIGNAL(timeout()), this, SLOT(onTimer()));

    m_tDumpTimer.start(m_iDumpIntervalMs);
}

/************************************************************************/

CTimeSampler::CTimeSampler(CLogger* pLogger)
    : m_tMutex()
    , m_tDumpTimer(this)
    , m_dLastFrameMs(0.0)
    , m_iFrameCount(0)
    , m_bFirstFrame(true)
    , m_iDumpIntervalMs(TimeSamplerDumpIntervalMs)
    , m_pLogger(pLogger)
{
    connect(&m_tDumpTimer, SIGNAL(timeout()), this, SLOT(onTimer()));

    m_tDumpTimer.start(m_iDumpIntervalMs);

    if (m_pLogger == nullptr)
    {
        m_pLogger = CLogger::getInstance();
    }
}

/************************************************************************/

CTimeSampler::~CTimeSampler()
{
    m_tDumpTimer.stop();
}

/************************************************************************/

void CTimeSampler::onTimer()
{
    m_tDumpTimer.stop();

    dumpAccumulatedTimes();

    m_tDumpTimer.start(m_iDumpIntervalMs);
}

/************************************************************************/

void CTimeSampler::beginFrame()
{
    if (m_tMutex.lock())
    {
        if (m_bFirstFrame == false)
        {
            m_dLastFrameMs = double(m_tFrameTimer.nsecsElapsed()) / 1000000.0;
        }
        else
        {
            m_bFirstFrame = false;
            m_dLastFrameMs = 0.0;
        }

        m_tFrameTimer.start();
        m_iFrameCount++;

        m_tMutex.unlock();
    }
}

/************************************************************************/

void CTimeSampler::startSample(const QString& sName)
{
    if (m_tMutex.lock())
    {
        QElapsedTimer tTimer;
        tTimer.start();
        m_mStartTimes[sName] = tTimer;

        if (m_mAccumTimesNs.contains(sName) == false)
        {
            m_mAccumTimesNs[sName] = 0;
            m_mMaxTimesNs[sName] = 0;
            m_mNumCalls[sName] = 0;
        }

        m_mNumCalls[sName]++;

        m_tMutex.unlock();
    }
}

/************************************************************************/

void CTimeSampler::stopSample(const QString& sName)
{
    if (m_tMutex.lock())
    {
        if (m_mStartTimes.contains(sName) == true)
        {
            qint64 iElapsedNs = m_mStartTimes[sName].nsecsElapsed();
            m_mStartTimes.remove(sName);

            m_mAccumTimesNs[sName] += iElapsedNs;

            if (iElapsedNs > m_mMaxTimesNs[sName])
            {
                m_mMaxTimesNs[sName] = iElapsedNs;
            }
        }

        m_tMutex.unlock();
    }
}

/************************************************************************/

void CTimeSampler::stopSampleAndLog(const QString& sName)
{
    qint64 iElapsedNs = 0;
    bool bFound = false;

    if (m_tMutex.lock())
    {
        if (m_mStartTimes.contains(sName) == true)
        {
            iElapsedNs = m_mStartTimes[sName].nsecsElapsed();
            m_mStartTimes.remove(sName);

            m_mAccumTimesNs[sName] += iElapsedNs;

            if (iElapsedNs > m_mMaxTimesNs[sName])
            {
                m_mMaxTimesNs[sName] = iElapsedNs;
            }

            bFound = true;
        }

        m_tMutex.unlock();
    }

    if (bFound == true)
    {
        double dElapsedMs = double(iElapsedNs) / 1000000.0;
        m_pLogger->log(llDebug, QString("%1 = %2 milliseconds").arg(sName).arg(dElapsedMs), "TimeSample");
    }
}

/************************************************************************/

void CTimeSampler::addSampleTime(const QString& sName, qint64 iElapsedNs)
{
    if (m_tMutex.lock())
    {
        if (m_mAccumTimesNs.contains(sName) == false)
        {
            m_mAccumTimesNs[sName] = 0;
            m_mMaxTimesNs[sName] = 0;
            m_mNumCalls[sName] = 0;
        }

        m_mAccumTimesNs[sName] += iElapsedNs;

        if (iElapsedNs > m_mMaxTimesNs[sName])
        {
            m_mMaxTimesNs[sName] = iElapsedNs;
        }

        m_mNumCalls[sName]++;

        m_tMutex.unlock();
    }
}

/************************************************************************/

void CTimeSampler::dumpAccumulatedTimes()
{
    // Snapshot under lock, then log from the copy: iterating the live maps
    // while samplers mutate them on other threads is undefined behavior.
    QMap<QString, qint64> mAccumTimesNs;
    QMap<QString, qint64> mMaxTimesNs;
    QMap<QString, qint64> mNumCalls;
    qint64 iFrameCount = 0;
    double dLastFrameMs = 0.0;

    if (m_tMutex.lock())
    {
        mAccumTimesNs = m_mAccumTimesNs;
        mMaxTimesNs = m_mMaxTimesNs;
        mNumCalls = m_mNumCalls;
        iFrameCount = m_iFrameCount;
        dLastFrameMs = m_dLastFrameMs;

        m_mAccumTimesNs.clear();
        m_mMaxTimesNs.clear();
        m_mNumCalls.clear();
        m_mStartTimes.clear();
        m_iFrameCount = 0;

        m_tMutex.unlock();
    }
    else
    {
        return;
    }

    if (iFrameCount == 0 && mNumCalls.isEmpty() == true)
    {
        return;
    }

    m_pLogger->log(llDebug, "------------------------------------------------------------", "TimeSample");
    m_pLogger->log(llDebug, QString("TimeSample frames = %1 last frame = %2 ms").arg(iFrameCount).arg(dLastFrameMs, 0, 'f', 3), "TimeSample");

    foreach (const QString& sName, mAccumTimesNs.keys())
    {
        qint64 iNumCalls = mNumCalls.value(sName, 0);

        if (iNumCalls <= 0)
        {
            continue;
        }

        double dTotalMs = double(mAccumTimesNs.value(sName, 0)) / 1000000.0;
        double dMaxMs = double(mMaxTimesNs.value(sName, 0)) / 1000000.0;
        double dAverageMs = 0.0;

        if (iFrameCount > 0)
        {
            dAverageMs = dTotalMs / double(iFrameCount);
        }

        m_pLogger->log(llDebug,
                       QString("  %1 total %2 ms avg %3 ms/frame max %4 ms calls %5")
                       .arg(sName)
                       .arg(dTotalMs, 0, 'f', 2)
                       .arg(dAverageMs, 0, 'f', 3)
                       .arg(dMaxMs, 0, 'f', 2)
                       .arg(iNumCalls), "TimeSample"
                       );
    }

    m_pLogger->log(llDebug, "------------------------------------------------------------", "TimeSample");
}

/************************************************************************/

void CTimeSampler::clear()
{
    if (m_tMutex.lock())
    {
        m_mAccumTimesNs.clear();
        m_mMaxTimesNs.clear();
        m_mNumCalls.clear();
        m_mStartTimes.clear();
        m_iFrameCount = 0;

        m_tMutex.unlock();
    }
}

/************************************************************************/

CScopedTimeSample::CScopedTimeSample(const QString& sName)
    : m_sName(sName)
{
    CTimeSampler::getInstance()->startSample(m_sName);
}

/************************************************************************/

CScopedTimeSample::~CScopedTimeSample()
{
    CTimeSampler::getInstance()->stopSample(m_sName);
}
