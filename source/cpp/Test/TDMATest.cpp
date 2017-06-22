
#include <QApplication>
#include <QDebug>

#include "TDMATest.h"

TestApplication::TestApplication(int argc, char** argv)
    : QApplication(argc, argv)
{
    m_pRelay = new SingleChannelDeviceRelay();
    m_pMaster = new SingleChannelDevice("Master", m_pRelay);
    m_pDevice1 = new SingleChannelDevice("Device 1", m_pRelay);
    m_pDevice2 = new SingleChannelDevice("Device 2", m_pRelay);

    m_pRelay->addDevice(m_pMaster);
    m_pRelay->addDevice(m_pDevice1);
    m_pRelay->addDevice(m_pDevice2);

    m_pTDMAMaster = new CTDMADevice(m_pMaster, 10, 2000, true);
    m_pTDMASlave1 = new CTDMADevice(m_pDevice1, 20);
    m_pTDMASlave2 = new CTDMADevice(m_pDevice2, 30);

    connect(m_pTDMAMaster, SIGNAL(readyRead()), this, SLOT(onMasterReadyRead()));
    connect(m_pTDMASlave1, SIGNAL(readyRead()), this, SLOT(onSlave1ReadyRead()));
    connect(m_pTDMASlave2, SIGNAL(readyRead()), this, SLOT(onSlave2ReadyRead()));

    connect(&m_tTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    m_tTimer.setInterval(3000);
    m_tTimer.setSingleShot(true);
    m_tTimer.start();
}

void TestApplication::onMasterReadyRead()
{
    QString sText;

    sText = m_pTDMAMaster->readFromSerial(20);
    qDebug() << "Master reads from 20 : " << sText;

    sText = m_pTDMAMaster->readFromSerial(30);
    qDebug() << "Master reads from 30 : " << sText;
}

void TestApplication::onSlave1ReadyRead()
{
    QString sText = m_pTDMASlave1->readAll();
    qDebug() << "Slave1 reads : " << sText;
}

void TestApplication::onSlave2ReadyRead()
{
    QString sText = m_pTDMASlave2->readAll();
    qDebug() << "Slave2 reads : " << sText;
}

void TestApplication::onTimeout()
{
    m_pTDMASlave1->write(QByteArray(QString("Hello").toUtf8()));
}

void TestApplication::onFinished()
{
    quit();
}

int main(int argc, char** argv)
{
    TestApplication app(argc, argv);

    return app.exec();
}
