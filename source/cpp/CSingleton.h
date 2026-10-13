
#pragma once

// std
#include <typeinfo>

// Qt
#include <QString>
#include <QMutexLocker>

// Application
#include "CSingletonPool.h"

//-------------------------------------------------------------------------------------------------

//! Defines a singleton pattern
template<class T>
class CSingleton
{
public:

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Gets the unique instance of the class
    static T* getInstance()
    {
        CSingletonPool::init();

        QMutexLocker locker(&CSingletonPool::s_tMutex);

        QString sClassName(typeid(T).name());

        if (CSingletonPool::s_pSingletons->contains(sClassName) == false)
        {
            (*CSingletonPool::s_pSingletons)[sClassName] = new T();
        }

        return static_cast<T*>((*CSingletonPool::s_pSingletons)[sClassName]);
    }

    //! Destroys the unique instance of the class
    static void killInstance()
    {
        CSingletonPool::init();

        QMutexLocker locker(&CSingletonPool::s_tMutex);

        QString sClassName(typeid(T).name());

        if (CSingletonPool::s_pSingletons->contains(sClassName))
        {
            delete static_cast<T*>((*CSingletonPool::s_pSingletons)[sClassName]);
            CSingletonPool::s_pSingletons->remove(sClassName);
        }
    }

    //-------------------------------------------------------------------------------------------------
    // Protected methods
    //-------------------------------------------------------------------------------------------------

protected:

    //! Constructor
    CSingleton() {}

    //! Destructor
    virtual ~CSingleton() {}
};
