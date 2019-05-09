
#pragma once

// Qt
#include <QObject>
#include <QMap>
#include <QDateTime>
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

    //! Starts sampling
    void startSample(const QString& sName);

    //! Stops sampling
    void stopSample(const QString& sName);

    //! Stops sampling and log results
    void stopSampleAndLog(const QString& sName);

    void dumpAccumulatedTimes();

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

private slots:

    void onTimer();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

private:

    CTracableMutex              m_tMutex;
    QMap<QString, QDateTime>    m_mStartTimes;
    QMap<QString, qint64>       m_mAccumTimes;
    QMap<QString, qint64>       m_mNumCalls;
    QTimer                      m_tDumpTimer;
    CLogger*                    m_pLogger;
};
