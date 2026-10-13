
// Qt
#include <QDebug>
#include <QMutexLocker>

// Application
#include "CSingletonPool.h"

//-------------------------------------------------------------------------------------------------

Q_DECL_EXPORT QMap<QString, void*>* CSingletonPool::s_pSingletons = nullptr;
Q_DECL_EXPORT QRecursiveMutex CSingletonPool::s_tMutex;

//-------------------------------------------------------------------------------------------------

void CSingletonPool::init()
{
    QMutexLocker locker(&s_tMutex);

    if (s_pSingletons == nullptr)
    {
        s_pSingletons = new QMap<QString, void*>;
    }
}
