
#pragma once

// std
#include <typeinfo>

// Qt
#include <QObject>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QString>
#include <QTimer>
#include <QVector>
#include <QMutex>

// Application
#include "qtplus_global.h"
#include "CSingleton.h"
#include "CXMLNode.h"
#include "File/CRollingFiles.h"

//-------------------------------------------------------------------------------------------------
// Use the following macros to log

#ifdef WIN32
#define __FILE_NOPATH__         (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define __PRETTY_FUNCTION__     (__func__)
#else
#define __FILE_NOPATH__         (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define __PRETTY_FUNCTION__     (__func__)
#endif

#ifndef NO_LOGGING
#define LOG_DEBUG(a)            CLogger::getInstance()->log(llDebug,    a, __FILE_NOPATH__)
#define LOG_INFO(a)             CLogger::getInstance()->log(llInfo,     a, __FILE_NOPATH__)
#define LOG_WARNING(a)          CLogger::getInstance()->log(llWarning,  a, __FILE_NOPATH__)
#define LOG_ERROR(a)            CLogger::getInstance()->log(llError,    a, __FILE_NOPATH__)
#define LOG_CRITICAL(a)         CLogger::getInstance()->log(llCritical, a, __FILE_NOPATH__)
#define LOG_ALWAYS(a)           CLogger::getInstance()->log(llAlways,   a, __FILE_NOPATH__)
#define LOG_BUFFER(l,b,s)       CLogger::getInstance()->logBuffer (l,b,s)

#define LOG_DEBUG_TOKEN(a,b)    CLogger::getInstance()->log(llDebug,a,b)
#define LOG_INFO_TOKEN(a,b)     CLogger::getInstance()->log(llInfo,a,b)
#define LOG_WARNING_TOKEN(a,b)  CLogger::getInstance()->log(llWarning,a,b)
#define LOG_ERROR_TOKEN(a,b)    CLogger::getInstance()->log(llError,a,b)
#define LOG_CRITICAL_TOKEN(a)   CLogger::getInstance()->log(llCritical,a,b)
#define LOG_ALWAYS_TOKEN(a,b)   CLogger::getInstance()->log(llAlways,a,b)

#define LOG_METHOD_DEBUG(a)     LOG_DEBUG(QString("%1::%2() : %3").arg(typeid(*this).name()).arg(__PRETTY_FUNCTION__).arg(a))
#define LOG_METHOD_INFO(a)      LOG_INFO(QString("%1::%2() : %3").arg(typeid(*this).name()).arg(__PRETTY_FUNCTION__).arg(a))
#define LOG_METHOD_WARNING(a)   LOG_WARNING(QString("%1::%2() : %3").arg(typeid(*this).name()).arg(__PRETTY_FUNCTION__).arg(a))
#define LOG_METHOD_ERROR(a)     LOG_ERROR(QString("%1::%2() : %3").arg(typeid(*this).name()).arg(__PRETTY_FUNCTION__).arg(a))
#define LOG_METHOD_CRITICAL(a)  LOG_CRITICAL(QString("%1::%2() : %3").arg(typeid(*this).name()).arg(__PRETTY_FUNCTION__).arg(a))
#else
#define LOG_DEBUG(a)
#define LOG_INFO(a)
#define LOG_WARNING(a)
#define LOG_ERROR(a)
#define LOG_CRITICAL(a)
#define LOG_ALWAYS(a)
#define LOG_BUFFER(l,b,s)

#define LOG_DEBUG_TOKEN(a,b)
#define LOG_INFO_TOKEN(a,b)
#define LOG_WARNING_TOKEN(a,b)
#define LOG_ERROR_TOKEN(a,b)
#define LOG_CRITICAL_TOKEN(a,b)
#define LOG_ALWAYS_TOKEN(a,b)

#define LOG_METHOD_DEBUG(a)
#define LOG_METHOD_INFO(a)
#define LOG_METHOD_WARNING(a)
#define LOG_METHOD_ERROR(a)
#define LOG_METHOD_CRITICAL(a)
#endif

//-------------------------------------------------------------------------------------------------

#define LOGGER_PARAM_TOKENS     "Tokens"
#define LOGGER_PARAM_LEVEL      "Level"
#define LOGGER_PARAM_DISPLAY    "Display"
#define LOGGER_PARAM_IGNORE     "Ignore"
#define LOGGER_PARAM_BACKUP     "Backup"
#define LOGGER_PARAM_ACTIVE     "Active"

enum ELogLevel
{
    llDebug,
    llInfo,
    llWarning,
    llError,
    llCritical,
    llAlways
};

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CLogger : public QObject, public CRollingFiles, public CSingleton<CLogger>
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    // Those are public to enable creation of additional loggers
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CLogger();

    //! Constructeur with file name
    CLogger(QString sPath, QString sFileName);

    //! Destructor
    virtual ~CLogger();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Defines the log level
    virtual void setLevel(const QString& sLevel);

    //! Defines the log level
    virtual void setLevel(ELogLevel eLevel);

    //! Defines the token list to log
    void setDisplayTokens(const QString& sTokens);

    //! Defines the token list to ignore
    void setIgnoreTokens(const QString& sTokens);

    //! Sets the maximum file size
    void setMaxFileSize(int iValue);

    //! Defines if file back up is active
    void setBackupActive(bool value);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the path name
    QString pathName() const;

    //! Returns the maximum file size
    int maxFileSize() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Initializes the logger
    virtual void initialize(QString sPath, QString sFileName, CXMLNode xParameters);

    //! Registers a chained logger
    void registerChainedLogger(CLogger* logger);

    //! Unregisters a chained logger
    void unregisterChainedLogger(CLogger* logger);

    //! Returns true if the token should be logged
    bool filterToken(QString sToken);

    //! Logs a line
    virtual void log(ELogLevel eLevel, const QString& sText, const QString& sToken = "");

    //! Logs a buffer
    virtual void logBuffer(ELogLevel eLevel, const char* pBuffer, int iSize);

    //! Flushes file contents to dosk (use only when necessary)
    virtual void flush();

    //-------------------------------------------------------------------------------------------------
    // Protected methods
    //-------------------------------------------------------------------------------------------------

protected:

    //! Returns a final short string to write in the log file
    QString getShortStringForLevel(ELogLevel eLevel, const QString& sText);

    //! Returns a final string to write in the log file
    QString getFinalStringForLevel(ELogLevel eLevel, const QString& sText);

    //-------------------------------------------------------------------------------------------------
    // Protected slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    //!
    void onTimeout();

    //!
    void onFlushTimeout();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMutex              m_tMutex;
    QTimer              m_tTimer;
    QTimer              m_tFlushTimer;
    QString             m_sPathName;
    QFile*              m_pFile;
    qint64              m_iFileSize;
    ELogLevel           m_eLogLevel;
    QStringList         m_sDisplayTokens;
    QStringList         m_sIgnoreTokens;
    QVector<CLogger*>   m_vChainedLoggers;
    int                 m_iMaxFileSize;
    bool                m_bBackupActive;
};
