
#pragma once

#include <QApplication>
#include <QThread>
#include <QTimer>

#include "SingleChannelDeviceRelay.h"
#include "SingleChannelDevice.h"
#include "../CTDMADevice.h"

class TestApplication : public QApplication
{
    Q_OBJECT

public:

    TestApplication(int argc, char** argv);

protected slots:

    void onMasterReadyRead();
    void onSlave1ReadyRead();
    void onSlave2ReadyRead();

    void onTimeout();

    void onFinished();

protected:

    SingleChannelDeviceRelay*   m_pRelay;
    SingleChannelDevice*        m_pMaster;
    SingleChannelDevice*        m_pDevice1;
    SingleChannelDevice*        m_pDevice2;
    CTDMADevice*                m_pTDMAMaster;
    CTDMADevice*                m_pTDMASlave1;
    CTDMADevice*                m_pTDMASlave2;
    QTimer                      m_tTimer;
};
