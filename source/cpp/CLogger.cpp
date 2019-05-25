
// Qt
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

// Application
#include "CLogger.h"

//-------------------------------------------------------------------------------------------------
// Constants

#define DEFAULT_MAX_FILE_SIZE   (10 * 1024 * 1024)	// 10 mb

//-------------------------------------------------------------------------------------------------

CLogger::CLogger()
    : m_tMutex(QMutex::Recursive)
    , m_tTimer(this)
    , m_tFlushTimer(this)
    , m_pFile(nullptr)
    , m_iFileSize(0)
    , m_eLogLevel(llDebug)
    , m_iMaxFileSize(DEFAULT_MAX_FILE_SIZE)
    , m_bBackupActive(true)
{
    QString sName = QCoreApplication::applicationFilePath().split("/").last();
    QString sPath = QCoreApplication::applicationDirPath() + "/Logs";
    QString sFinal = QString("%1.log").arg(sName);

    initialize(sPath, sFinal, CXMLNode());

    connect(&m_tTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    connect(&m_tFlushTimer, SIGNAL(timeout()), this, SLOT(onFlushTimeout()));

    m_tTimer.start(1000);
    m_tFlushTimer.start(2000);
}

//-------------------------------------------------------------------------------------------------

CLogger::CLogger(QString sPath, QString sFileName)
    : m_tMutex(QMutex::Recursive)
    , m_tTimer(this)
    , m_tFlushTimer(this)
    , m_pFile(nullptr)
    , m_iFileSize(0)
    , m_eLogLevel(llDebug)
    , m_iMaxFileSize(DEFAULT_MAX_FILE_SIZE)
    , m_bBackupActive(false)
{
    initialize(sPath, sFileName, CXMLNode());

    connect(&m_tTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    connect(&m_tFlushTimer, SIGNAL(timeout()), this, SLOT(onFlushTimeout()));

    m_tTimer.start(1000);
    m_tFlushTimer.start(2000);
}

//-------------------------------------------------------------------------------------------------

CLogger::~CLogger()
{
    // !!!! DON'T LOG IN THE DESTRUCTOR !!!!

    QMutexLocker locker(&m_tMutex);

    if (m_pFile != nullptr)
    {
        if (m_pFile->isOpen())
        {
            m_pFile->close();
        }

        delete m_pFile;
    }
}

//-------------------------------------------------------------------------------------------------

void CLogger::setLevel(ELogLevel eLevel)
{
    QMutexLocker locker(&m_tMutex);

    m_eLogLevel = eLevel;
}

//-------------------------------------------------------------------------------------------------

void CLogger::setLevel(const QString& sLevel)
{
    QMutexLocker locker(&m_tMutex);

    if (sLevel.toLower() == "debug")
    {
        setLevel(llDebug);
    }
    else if (sLevel.toLower() == "info")
    {
        setLevel(llInfo);
    }
    else if (sLevel.toLower() == "warning")
    {
        setLevel(llWarning);
    }
    else if (sLevel.toLower() == "error")
    {
        setLevel(llError);
    }
    else if (sLevel.toLower() == "critical")
    {
        setLevel(llCritical);
    }
    else if (sLevel.toLower() == "always")
    {
        setLevel(llAlways);
    }
}

//-------------------------------------------------------------------------------------------------

void CLogger::setDisplayTokens(const QString& sTokens)
{
    if (sTokens == "")
    {
        m_sDisplayTokens.clear();
    }
    else
    {
        m_sDisplayTokens = sTokens.split("|");
    }
}

//-------------------------------------------------------------------------------------------------

void CLogger::setIgnoreTokens(const QString& sTokens)
{
    if (sTokens == "")
    {
        m_sIgnoreTokens.clear();
    }
    else
    {
        m_sIgnoreTokens = sTokens.split("|");
    }
}

//-------------------------------------------------------------------------------------------------

void CLogger::setMaxFileSize(int iValue)
{
    m_iMaxFileSize = iValue;
}

//-------------------------------------------------------------------------------------------------

void CLogger::setBackupActive(bool value)
{
    m_bBackupActive = value;
}

//-------------------------------------------------------------------------------------------------

QString CLogger::pathName() const
{
    return m_sPathName;
}

//-------------------------------------------------------------------------------------------------

int CLogger::maxFileSize() const
{
    return m_iMaxFileSize;
}

//-------------------------------------------------------------------------------------------------

void CLogger::initialize(QString sPath, QString sFileName, CXMLNode xParameters)
{
#ifndef NO_LOGGING

    QMutexLocker locker(&m_tMutex);

    CXMLNode xTokensNode = xParameters.getNodeByTagName(LOGGER_PARAM_TOKENS);
    CXMLNode xBackupNode = xParameters.getNodeByTagName(LOGGER_PARAM_BACKUP);

    // Read parameters
    if (xParameters.attributes()[LOGGER_PARAM_LEVEL].isEmpty() == false)
    {
        setLevel(xParameters.attributes()[LOGGER_PARAM_LEVEL]);
    }

    if (xTokensNode.attributes()[LOGGER_PARAM_DISPLAY].isEmpty() == false)
    {
        setDisplayTokens(xTokensNode.attributes()[LOGGER_PARAM_DISPLAY]);
    }

    if (xTokensNode.attributes()[LOGGER_PARAM_IGNORE].isEmpty() == false)
    {
        setIgnoreTokens(xTokensNode.attributes()[LOGGER_PARAM_IGNORE]);
    }

    if (xBackupNode.attributes()[LOGGER_PARAM_ACTIVE].isEmpty() == false)
    {
        m_bBackupActive = (bool) xBackupNode.attributes()[LOGGER_PARAM_ACTIVE].toInt();
    }

    // Assign file name
    m_sPathName = sPath;
    m_sFileName = sPath + "/" + sFileName;

    // Create target folder if needed
    if (QDir().exists(sPath) == false)
    {
        QDir().mkpath(sPath);
    }

    // Backup
    if (m_bBackupActive)
    {
        backup();
    }

    // Destroy the file
    if (m_pFile != nullptr)
    {
        if (m_pFile->isOpen())
        {
            m_pFile->close();
        }
        delete m_pFile;
    }

    // Create the file
    m_pFile = new QFile(m_sFileName);
    m_pFile->open(QIODevice::WriteOnly | QIODevice::Text);
    m_iFileSize = 0;

#endif
}

//-------------------------------------------------------------------------------------------------

void CLogger::registerChainedLogger(CLogger* pLogger)
{
    if (m_vChainedLoggers.contains(pLogger) == false)
    {
        m_vChainedLoggers.append(pLogger);
    }
}

//-------------------------------------------------------------------------------------------------

void CLogger::unregisterChainedLogger(CLogger* pLogger)
{
    m_vChainedLoggers.removeAll(pLogger);
}

//-------------------------------------------------------------------------------------------------

bool CLogger::filterToken(QString sToken)
{
    if (m_sDisplayTokens.size() > 0)
    {
        bool bFound = false;

        for (QString sDisplay : m_sDisplayTokens)
        {
            if (sToken.contains(sDisplay, Qt::CaseInsensitive))
            {
                bFound = true;
                break;
            }
        }

        return bFound;
    }

    if (m_sIgnoreTokens.size() > 0)
    {
        bool bFound = false;

        for (QString sDisplay : m_sIgnoreTokens)
        {
            if (sToken.contains(sDisplay, Qt::CaseInsensitive))
            {
                bFound = true;
                break;
            }
        }

        return !bFound;
    }

    return true;
}

//-------------------------------------------------------------------------------------------------

void CLogger::log(ELogLevel eLevel, const QString& sText, const QString& sToken)
{
    QMutexLocker locker(&m_tMutex);
    QString sFinalText = sText;

    // Is the token accepted?
    if (filterToken(sToken) == false) return;

    // Add the token in the text
    if (sToken != "")
    {
        sFinalText = "<" + sToken + "> " + sText;
    }

    // Replace undesirable characters
    sFinalText = sFinalText.replace("\"", "'");

    if (eLevel >= llError)
    {
        qDebug() << getShortStringForLevel(eLevel, sFinalText).toLatin1().constData();
    }

    if (m_pFile && m_pFile->isOpen())
    {
        switch (eLevel)
        {
            case llDebug :
            {
                if (m_eLogLevel <= llDebug)
                {
                    m_iFileSize += m_pFile->write(getFinalStringForLevel(llDebug, sFinalText).toLatin1().constData());
                }
                break;
            }

            case llInfo :
            {
                if (m_eLogLevel <= llInfo)
                {
                    m_iFileSize += m_pFile->write(getFinalStringForLevel(llInfo, sFinalText).toLatin1().constData());
                }
                break;
            }

            case llWarning :
            {
                if (m_eLogLevel <= llWarning)
                {
                    m_iFileSize += m_pFile->write(getFinalStringForLevel(llWarning, sFinalText).toLatin1().constData());

                    for (CLogger* pLogger : m_vChainedLoggers) { pLogger->log(eLevel, sFinalText, sToken); }
                }
                break;
            }

            case llError :
            {
                if (m_eLogLevel <= llError)
                {
                    m_iFileSize += m_pFile->write(getFinalStringForLevel(llError, sFinalText).toLatin1().constData());

                    for (CLogger* pLogger : m_vChainedLoggers) { pLogger->log(eLevel, sFinalText, sToken); }
                }
                break;
            }

            case llCritical :
            {
                if (m_eLogLevel <= llCritical)
                {
                    m_iFileSize += m_pFile->write(getFinalStringForLevel(llCritical, sFinalText).toLatin1().constData());

                    for (CLogger* pLogger : m_vChainedLoggers) { pLogger->log(eLevel, sFinalText, sToken); }
                }
                break;
            }

            case llAlways :
            {
                if (m_eLogLevel <= llAlways)
                {
                    m_iFileSize += m_pFile->write(getFinalStringForLevel(llAlways, sFinalText).toLatin1().constData());

                    for (CLogger* pLogger : m_vChainedLoggers) { pLogger->log(eLevel, sFinalText, sToken); }
                }
                break;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CLogger::logBuffer(ELogLevel eLevel, const char* pBuffer, int iSize)
{
    QMutexLocker locker(&m_tMutex);

    const char* pPointer = pBuffer;

    log(eLevel, "Buffer :");

    while (pPointer < pBuffer + iSize)
    {
        QString sText = "";

        for (int iIndex = 0; iIndex < 16 && (pPointer < pBuffer + iSize); iIndex++)
        {
            if (sText != "") sText += " ";
            sText += QString("0x%1").arg(*((const unsigned char*) pPointer), 2 , 16 , QChar('0'));
            pPointer++;
        }

        log(eLevel, sText);
    }
}

//-------------------------------------------------------------------------------------------------

void CLogger::flush()
{
    QMutexLocker locker(&m_tMutex);

    if (m_pFile != nullptr)
    {
        m_pFile->flush();
    }
}

//-------------------------------------------------------------------------------------------------

QString CLogger::getShortStringForLevel(ELogLevel eLevel, const QString& sText)
{
    QString sLogLevel;

    switch (eLevel)
    {
        case llDebug	: sLogLevel = "DEBUG"; break;
        case llInfo		: sLogLevel = "INFO"; break;
        case llWarning	: sLogLevel = "WARNING"; break;
        case llError	: sLogLevel = "ERROR"; break;
        case llCritical	: sLogLevel = "CRITICAL"; break;
        case llAlways	: sLogLevel = "ALWAYS"; break;
    }

    QString sFinalText = QString("[%1] - %2\n")
            .arg(sLogLevel)
            .arg(sText);

    return sFinalText;
}

//-------------------------------------------------------------------------------------------------

QString CLogger::getFinalStringForLevel(ELogLevel eLevel, const QString& sText)
{
    QString sLogLevel;

    switch (eLevel)
    {
        case llDebug	: sLogLevel = "DEBUG"; break;
        case llInfo		: sLogLevel = "INFO"; break;
        case llWarning	: sLogLevel = "WARNING"; break;
        case llError	: sLogLevel = "ERROR"; break;
        case llCritical	: sLogLevel = "CRITICAL"; break;
        case llAlways	: sLogLevel = "ALWAYS"; break;
    }

    QDateTime tNow = QDateTime::currentDateTime();

    QString sFinalText = QString("%1-%2-%3 %4:%5:%6.%7 [%8] - %9\n")
            .arg(tNow.date().year())
            .arg(tNow.date().month())
            .arg(tNow.date().day())
            .arg(tNow.time().hour())
            .arg(tNow.time().minute())
            .arg(tNow.time().second())
            .arg(tNow.time().msec())
            .arg(sLogLevel)
            .arg(sText);

    return sFinalText;
}

//-------------------------------------------------------------------------------------------------

void CLogger::onTimeout()
{
    QMutexLocker locker(&m_tMutex);

    if (m_pFile != nullptr)
    {
        if (m_iFileSize > m_iMaxFileSize)
        {
            // Close the file
            m_pFile->close();
            delete m_pFile;

            // Backup if needed
            if (m_bBackupActive)
            {
                backup();
            }

            // Create the file
            m_pFile = new QFile(m_sFileName);
            m_pFile->open(QIODevice::WriteOnly | QIODevice::Text);
            m_iFileSize = 0;
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CLogger::onFlushTimeout()
{
    flush();
}
