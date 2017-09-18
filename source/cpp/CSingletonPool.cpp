
// Qt
#include <QDebug>

// Application
#include "CSingletonPool.h"

//-------------------------------------------------------------------------------------------------

Q_DECL_EXPORT QMap<QString, void*>* CSingletonPool::s_pSingletons;

//-------------------------------------------------------------------------------------------------

void CSingletonPool::init()
{
    if (s_pSingletons == nullptr)
    {
        s_pSingletons = new QMap<QString, void*>;
    }
}
