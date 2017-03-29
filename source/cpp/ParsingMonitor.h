
#pragma once

#include <QObject>
#include <QDebug>

#include "QMLTree/QMLTreeContext.h"
#include "QMLTree/QMLAnalyzer.h"

class ParsingMonitor : public QObject
{
    Q_OBJECT

public:

    ParsingMonitor(QMLTreeContext* pContext);

    ParsingMonitor(QMLAnalyzer* pAnalyzer);

    virtual ~ParsingMonitor();

    void setOutputFileName(const QString& sFileName);

protected slots:

    void onParsingStarted(QString sFileName);

    void onParsingFinished(QString sFileName);

    void onImportParsingStarted(QString sFileName);

    void onAnalyzeError(QMLAnalyzerError sError);

private:

    QString m_sOutputFileName;
    QFile*  m_pOutputFile;
};
