
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
}

void ParsingMonitor::onParsingStarted(QString sFileName)
{
    qDebug() << "Parsing started for " << sFileName;
}

void ParsingMonitor::onParsingFinished(QString sFileName)
{
    qDebug() << "Parsing finished for " << sFileName;
}

void ParsingMonitor::onImportParsingStarted(QString sFileName)
{
    qDebug() << "Import parsing started for " << sFileName;
}
