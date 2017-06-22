
#include "SingleChannelDevice.h"
#include "SingleChannelDeviceRelay.h"

SingleChannelDevice::SingleChannelDevice(QString sName, SingleChannelDeviceRelay* pRelay)
    : m_sName(sName)
    , m_pRelay(pRelay)
{
    connect(m_pRelay, SIGNAL(readyRead(SingleChannelDevice*)), this, SLOT(onReadyRead(SingleChannelDevice*)), Qt::QueuedConnection);

    QIODevice::open(QIODevice::ReadWrite);
}

SingleChannelDevice::~SingleChannelDevice()
{
}

qint64 SingleChannelDevice::readData(char* data, qint64 maxSize)
{
    if (m_pRelay != nullptr)
    {
        return m_pRelay->readData(this, data, maxSize);
    }

    return 0;
}

qint64 SingleChannelDevice::writeData(const char * data, qint64 maxSize)
{
    if (m_pRelay != nullptr)
    {
        return m_pRelay->writeData(this, data, maxSize);
    }

    return 0;
}

void SingleChannelDevice::onReadyRead(SingleChannelDevice* pDevice)
{
    if (pDevice == this)
    {
        emit readyRead();
    }
}
