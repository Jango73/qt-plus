
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
    void onSlave3ReadyRead();

    void onTimeout();

    void onFinished();

protected:

    SingleChannelDeviceRelay*   m_pRelay;
    SingleChannelDevice*        m_pMaster;
    SingleChannelDevice*        m_pDevice1;
    SingleChannelDevice*        m_pDevice2;
    SingleChannelDevice*        m_pDevice3;
    CTDMADevice*                m_pTDMAMaster;
    CTDMADevice*                m_pTDMASlave1;
    CTDMADevice*                m_pTDMASlave2;
    CTDMADevice*                m_pTDMASlave3;
    QTimer                      m_tTimer;
    QTimer                      m_tTimer2;
    QTimer                      m_tTimer3;
    int                         m_iSequence;
};
