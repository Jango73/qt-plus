
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

protected slots:

    void onParsingStarted(QString sFileName);

    void onParsingFinished(QString sFileName);

    void onImportParsingStarted(QString sFileName);
};
