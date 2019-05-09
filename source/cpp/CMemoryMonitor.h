
#pragma once

#include "qtplus_global.h"

// Qt
#include <QString>
#include <QMap>

// Application
#include "CSingleton.h"

//-------------------------------------------------------------------------------------------------

#define DECLARE_MEMORY_MONITORED                                        \
public:                                                                 \
    void* operator new (size_t size);                                   \
    void operator delete(void* ptr, size_t size);

#define IMPLEMENT_MEMORY_MONITORED(t, n)                                \
void* t::operator new (size_t size)                                     \
{                                                                       \
    CMemoryMonitor::getInstance()->allocBytes(n, size);                 \
    return malloc(size);                                                \
}                                                                       \
void t::operator delete(void* ptr, size_t size)                         \
{                                                                       \
    CMemoryMonitor::getInstance()->freeBytes(n, size);                  \
    free(ptr);                                                          \
}

//-------------------------------------------------------------------------------------------------

// Defines a memory monitoring object
class QTPLUSSHARED_EXPORT CMemoryMonitor : public CSingleton<CMemoryMonitor>
{
    friend class CSingleton<CMemoryMonitor>;

protected:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    CMemoryMonitor();

    //! Destructor
    virtual ~CMemoryMonitor() Q_DECL_OVERRIDE;

public:

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    qint64 allocatedBytes() const;

    //!
    qint64 allocatedBytes(const QString& sClassName) const;

    //!
    const QMap<QString, qint64>& allocationMap() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    void allocBytes(const QString& sClassName, qint64 iBytes);

    //!
    void freeBytes(const QString& sClassName, qint64 iBytes);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMap<QString, qint64>   m_mAllocatedBytes;
};
