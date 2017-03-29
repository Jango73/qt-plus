
#include "ParsingMonitor.h"

ParsingMonitor::ParsingMonitor(QMLTreeContext* pContext)
    : m_pOutputFile(nullptr)
{
    connect(pContext, SIGNAL(parsingStarted(QString)), this, SLOT(onParsingStarted(QString)), Qt::DirectConnection);
    connect(pContext, SIGNAL(parsingFinished(QString)), this, SLOT(onParsingFinished(QString)), Qt::DirectConnection);
    connect(pContext, SIGNAL(importParsingStarted(QString)), this, SLOT(onImportParsingStarted(QString)), Qt::DirectConnection);
}

ParsingMonitor::ParsingMonitor(QMLAnalyzer* pAnalyzer)
    : m_pOutputFile(nullptr)
{
    connect(pAnalyzer, SIGNAL(parsingStarted(QString)), this, SLOT(onParsingStarted(QString)), Qt::DirectConnection);
    connect(pAnalyzer, SIGNAL(parsingFinished(QString)), this, SLOT(onParsingFinished(QString)), Qt::DirectConnection);
    connect(pAnalyzer, SIGNAL(importParsingStarted(QString)), this, SLOT(onImportParsingStarted(QString)), Qt::DirectConnection);
    connect(pAnalyzer, SIGNAL(analyzeError(QMLAnalyzerError)), this, SLOT(onAnalyzeError(QMLAnalyzerError)), Qt::DirectConnection);
}

ParsingMonitor::~ParsingMonitor()
{
    if (m_pOutputFile != nullptr)
    {
        m_pOutputFile->close();
        delete m_pOutputFile;
    }
}

void ParsingMonitor::setOutputFileName(const QString& sFileName)
{
    m_sOutputFileName = sFileName;

    if (m_sOutputFileName.isEmpty() == false)
    {
        m_pOutputFile = new QFile(sFileName);
        m_pOutputFile->open(QFile::WriteOnly);
    }
}

void ParsingMonitor::onParsingStarted(QString sFileName)
{
    qDebug() << "------------------------------------------------------------";
    qDebug() << "Parsing " << sFileName << " ...";
}

void ParsingMonitor::onParsingFinished(QString sFileName)
{
    Q_UNUSED(sFileName);
    qDebug() << "Done";
}

void ParsingMonitor::onImportParsingStarted(QString sFileName)
{
    qDebug() << "Parsing import " << sFileName << " ...";
}

void ParsingMonitor::onAnalyzeError(QMLAnalyzerError sError)
{
    qDebug() << sError.toString();

    if (m_pOutputFile != nullptr)
    {
        m_pOutputFile->write((sError.toString() + "\n").toLatin1());
    }
}
