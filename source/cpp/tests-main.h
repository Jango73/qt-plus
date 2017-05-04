
#pragma once

#include <QApplication>
#include <QThread>

#include "CGeoUtilities.h"
#include "QTree.h"
#include "QMLTree/QMLTreeContext.h"
#include "QMLTree/QMLAnalyzer.h"
#include "ParsingMonitor.h"

class TestRunner : public QThread
{
    Q_OBJECT

public:

    virtual void run() Q_DECL_OVERRIDE;

    void runGeoCoordTests();
    void runQTreeTests();
    void runQMLTreeTests();
    void runQMLAnalyzerTests();
    void runThreadedQMLAnalyzerTests();
};

class TestApplication : public QApplication
{
    Q_OBJECT

public:

    TestApplication(int argc, char** argv);

    TestRunner runner;

protected slots:

    void onFinished();
};
