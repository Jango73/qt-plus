
// Application
#include "CMemoryMonitor.h"

//-------------------------------------------------------------------------------------------------

CMemoryMonitor::CMemoryMonitor()
{
}

//-------------------------------------------------------------------------------------------------

CMemoryMonitor::~CMemoryMonitor()
{
}

//-------------------------------------------------------------------------------------------------

qint64 CMemoryMonitor::allocatedBytes() const
{
    qint64 iReturnValue = 0;

    for (QString sKey : m_mAllocatedBytes.keys())
    {
        iReturnValue += m_mAllocatedBytes[sKey];
    }

    return iReturnValue;
}

//-------------------------------------------------------------------------------------------------

qint64 CMemoryMonitor::allocatedBytes(const QString& sClassName) const
{
    return m_mAllocatedBytes[sClassName];
}

//-------------------------------------------------------------------------------------------------

const QMap<QString, qint64>& CMemoryMonitor::allocationMap() const
{
    return m_mAllocatedBytes;
}

//-------------------------------------------------------------------------------------------------

void CMemoryMonitor::allocBytes(const QString& sClassName, qint64 iBytes)
{
    if (m_mAllocatedBytes.contains(sClassName) == false)
    {
        m_mAllocatedBytes[sClassName] = 0;
    }

    m_mAllocatedBytes[sClassName] += iBytes;
}

//-------------------------------------------------------------------------------------------------

void CMemoryMonitor::freeBytes(const QString& sClassName, qint64 iBytes)
{
    m_mAllocatedBytes[sClassName] -= iBytes;
}
