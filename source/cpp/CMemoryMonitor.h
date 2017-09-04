
#pragma once

#include "qtplus_global.h"

// Qt
#include <QString>
#include <QMap>

// Application
#include "CSingleton.h"

//-------------------------------------------------------------------------------------------------

#define MM_NEW(t) { CMemoryMonitor::getInstance()->allocBytes(sizeof(T));
#define MM_DEL(t) { CMemoryMonitor::getInstance()->freeBytes(sizeof(T));

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
    virtual ~CMemoryMonitor();

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
