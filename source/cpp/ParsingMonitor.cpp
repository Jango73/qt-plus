
#include "ParsingMonitor.h"

ParsingMonitor::ParsingMonitor(QMLTreeContext* pContext)
{
    connect(pContext, SIGNAL(parsingStarted(QString)), this, SLOT(onParsingStarted(QString)), Qt::DirectConnection);
    connect(pContext, SIGNAL(parsingFinished(QString)), this, SLOT(onParsingFinished(QString)), Qt::DirectConnection);
    connect(pContext, SIGNAL(importParsingStarted(QString)), this, SLOT(onImportParsingStarted(QString)), Qt::DirectConnection);
}

ParsingMonitor::ParsingMonitor(QMLAnalyzer* pAnalyzer)
{
    connect(pAnalyzer, SIGNAL(parsingStarted(QString)), this, SLOT(onParsingStarted(QString)), Qt::DirectConnection);
    connect(pAnalyzer, SIGNAL(parsingFinished(QString)), this, SLOT(onParsingFinished(QString)), Qt::DirectConnection);
    connect(pAnalyzer, SIGNAL(importParsingStarted(QString)), this, SLOT(onImportParsingStarted(QString)), Qt::DirectConnection);
    connect(pAnalyzer, SIGNAL(analyzeError(QMLAnalyzerError)), this, SLOT(onAnalyzeError(QMLAnalyzerError)), Qt::DirectConnection);
}

void ParsingMonitor::onParsingStarted(QString sFileName)
{
    qDebug() << "------------------------------------------------------------" << sFileName;
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
}
