
#include "SingleChannelDeviceRelay.h"

SingleChannelDeviceRelay::SingleChannelDeviceRelay()
{
}

SingleChannelDeviceRelay::~SingleChannelDeviceRelay()
{
}

void SingleChannelDeviceRelay::addDevice(SingleChannelDevice* pDevice)
{
    m_mDevices[pDevice] = QByteArray();
}

qint64 SingleChannelDeviceRelay::readData(SingleChannelDevice* pCaller, char * data, qint64 maxSize)
{
    if (pCaller != nullptr)
    {
        if (m_mDevices.contains(pCaller))
        {
            if (maxSize > m_mDevices[pCaller].count())
            {
                maxSize = m_mDevices[pCaller].count();
            }

            if (maxSize > 0)
            {
                memcpy(data, m_mDevices[pCaller].constData(), maxSize);
                m_mDevices[pCaller].remove(0, maxSize);
            }
        }
    }

    return maxSize;
}

qint64 SingleChannelDeviceRelay::writeData(SingleChannelDevice* pCaller, const char * data, qint64 maxSize)
{
    foreach (SingleChannelDevice* pDevice, m_mDevices.keys())
    {
        if (pDevice != pCaller)
        {
             m_mDevices[pDevice].append(QByteArray(data, maxSize));
             emit readyRead(pDevice);
        }
    }

    return maxSize;
}
