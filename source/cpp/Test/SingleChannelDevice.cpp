
#include "SingleChannelDevice.h"
#include "SingleChannelDeviceRelay.h"

SingleChannelDevice::SingleChannelDevice(SingleChannelDeviceRelay* pRelay)
    : m_pRelay(pRelay)
{
}

SingleChannelDevice::~SingleChannelDevice()
{
}

qint64 SingleChannelDevice::readData(char* data, qint64 maxSize)
{
    if (m_pRelay != nullptr)
    {
        return m_pRelay->writeData(this, data, maxSize);
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
