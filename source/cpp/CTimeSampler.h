
#pragma once

// Qt
#include <QElapsedTimer>
#include <QMap>
#include <QObject>
#include <QString>
#include <QTimer>

// Application
#include "qtplus_global.h"
#include "CSingleton.h"
#include "CTracableMutex.h"

//-------------------------------------------------------------------------------------------------

#define START_SAMPLE(a)         CTimeSampler::getInstance()->startSample(a)
#define STOP_SAMPLE(a)          CTimeSampler::getInstance()->stopSample(a)
#define STOP_SAMPLE_AND_LOG(a)  CTimeSampler::getInstance()->stopSampleAndLog(a)

class CLogger;

class QTPLUSSHARED_EXPORT CTimeSampler : public QObject, public CSingleton<CTimeSampler>
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CTimeSampler();

    CTimeSampler(CLogger* pLogger);

    //! Destructor
    virtual ~CTimeSampler() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Marks the start of a new frame, increments the frame counter
    void beginFrame();

    //! Starts sampling
    void startSample(const QString& sName);

    //! Stops sampling
    void stopSample(const QString& sName);

    //! Stops sampling and log results
    void stopSampleAndLog(const QString& sName);

    //! Accumulates an externally measured duration in nanoseconds under sName
    void addSampleTime(const QString& sName, qint64 iElapsedNs);

    void dumpAccumulatedTimes();

    //! Clears all accumulated timings and the frame counter
    void clear();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the last frame duration in milliseconds
    double lastFrameMs() const { return m_dLastFrameMs; }

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

private slots:

    void onTimer();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

private:

    CTracableMutex m_tMutex;
    QMap<QString, QElapsedTimer> m_mStartTimes;
    QMap<QString, qint64> m_mAccumTimesNs;
    QMap<QString, qint64> m_mMaxTimesNs;
    QMap<QString, qint64> m_mNumCalls;
    QTimer m_tDumpTimer;
    QElapsedTimer m_tFrameTimer;
    double m_dLastFrameMs;
    qint64 m_iFrameCount;
    bool m_bFirstFrame;
    int m_iDumpIntervalMs;
    CLogger* m_pLogger;
};

//-------------------------------------------------------------------------------------------------

//! RAII helper timing one sampler section for its lifetime
class QTPLUSSHARED_EXPORT CScopedTimeSample
{
public:

    //!
    CScopedTimeSample(const QString& sName);

    //!
    ~CScopedTimeSample();

private:

    QString m_sName;
};
