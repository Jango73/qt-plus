
#pragma once

#include <QApplication>
#include <QThread>
#include <QImage>

#include "SingleChannelDeviceRelay.h"
#include "SingleChannelDevice.h"
#include "../CTDMADevice.h"

class TestRunner : public QThread
{
    Q_OBJECT

public:

    virtual void run() Q_DECL_OVERRIDE;
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
