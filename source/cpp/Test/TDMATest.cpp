
#include <QApplication>
#include <QDebug>

#include "TDMATest.h"

TestApplication::TestApplication(int argc, char** argv)
    : QApplication(argc, argv)
    , m_iSequence(0)
{
    m_pRelay = new SingleChannelDeviceRelay();
    m_pMaster = new SingleChannelDevice("Master", m_pRelay);
    m_pDevice1 = new SingleChannelDevice("Device1", m_pRelay);
    m_pDevice2 = new SingleChannelDevice("Device2", m_pRelay);
    m_pDevice3 = new SingleChannelDevice("Device3", m_pRelay);

    m_pRelay->addDevice(m_pMaster);
    m_pRelay->addDevice(m_pDevice1);
    m_pRelay->addDevice(m_pDevice2);
    m_pRelay->addDevice(m_pDevice3);

    m_pTDMAMaster = new CTDMADevice(m_pMaster, 10, 2000, true);
    m_pTDMASlave1 = new CTDMADevice(m_pDevice1, 20);
    m_pTDMASlave2 = new CTDMADevice(m_pDevice2, 30);
    m_pTDMASlave3 = new CTDMADevice(m_pDevice3, 40);

    connect(m_pTDMAMaster, SIGNAL(readyRead()), this, SLOT(onMasterReadyRead()), Qt::QueuedConnection);
    connect(m_pTDMASlave1, SIGNAL(readyRead()), this, SLOT(onSlave1ReadyRead()), Qt::QueuedConnection);
    connect(m_pTDMASlave2, SIGNAL(readyRead()), this, SLOT(onSlave2ReadyRead()), Qt::QueuedConnection);
    connect(m_pTDMASlave3, SIGNAL(readyRead()), this, SLOT(onSlave3ReadyRead()), Qt::QueuedConnection);

    connect(&m_tTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    m_tTimer.setInterval(1000);
    m_tTimer.start();
}

void TestApplication::onMasterReadyRead()
{
    QString sText;

    if (m_pTDMAMaster->bytesAvailableFromSerial(20) > 0)
    {
        sText = m_pTDMAMaster->readFromSerial(20);
        qDebug() << "Master reads from 20 : " << sText;
    }

    if (m_pTDMAMaster->bytesAvailableFromSerial(30) > 0)
    {
        sText = m_pTDMAMaster->readFromSerial(30);
        qDebug() << "Master reads from 30 : " << sText;
    }

    if (m_pTDMAMaster->bytesAvailableFromSerial(40) > 0)
    {
        sText = m_pTDMAMaster->readFromSerial(40);
        qDebug() << "Master reads from 40 : " << sText;
    }
}

void TestApplication::onSlave1ReadyRead()
{
    QString sText = m_pTDMASlave1->readAll();
    qDebug() << "20 reads : " << sText;
}

void TestApplication::onSlave2ReadyRead()
{
    QString sText = m_pTDMASlave2->readAll();
    qDebug() << "30 reads : " << sText;
}

void TestApplication::onSlave3ReadyRead()
{
    QString sText = m_pTDMASlave3->readAll();
    qDebug() << "40 reads : " << sText;
}

void TestApplication::onTimeout()
{
    if (m_iSequence < 1)
    {
        m_pTDMASlave1->write(QByteArray(QString("Hello from 20").toUtf8()));
        m_pTDMASlave2->write(QByteArray(QString("Hello from 30").toUtf8()));
        m_pTDMASlave3->write(QByteArray(QString("Hello from 40").toUtf8()));
    }
    else if (m_iSequence < 2)
    {
        m_pTDMAMaster->write(QByteArray(QString("How are you").toUtf8()));
    }
    else if (m_iSequence < 3)
    {
        m_pTDMASlave1->write(QByteArray(QString("Fine thanks").toUtf8()));
        m_pTDMASlave2->write(QByteArray(QString("Could be better").toUtf8()));
        m_pTDMASlave3->write(QByteArray(QString("Doing ok").toUtf8()));
    }

    m_iSequence++;
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
