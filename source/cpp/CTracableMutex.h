
#pragma once

// Qt
#include <QVector>
#include <QRecursiveMutex>
#include <QWaitCondition>

// Application
#include "qtplus_global.h"

// Commenter la ligne suivante en mode release
#define FULL_MUTEX_TRACE

class QTPLUSSHARED_EXPORT CTracableMutex
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with parameters
    CTracableMutex(QString sName = "");

    //! Copy constructor
    CTracableMutex(const CTracableMutex&);

    //! Destructor
    virtual ~CTracableMutex();

    //-------------------------------------------------------------------------------------------------
    // Operators
    //-------------------------------------------------------------------------------------------------

    //! Assign operator
    CTracableMutex& operator = (const CTracableMutex&);

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Returns \c true if mutex could be locked
    bool lock(QString sName = "");

    //! Unlocks the mutex
    void unlock();

    //-------------------------------------------------------------------------------------------------
    // Static control methods
    //-------------------------------------------------------------------------------------------------

    //! Resgisters a thread
    static void registerThread(int iThreadID, QString sName);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

    QRecursiveMutex                      m_tMutex;
    QString                     m_sName;

    static QMap<int, QString>   m_vThreadNames;

#ifdef FULL_MUTEX_TRACE
    QVector<QString>            m_sLockNames;
#endif
};
