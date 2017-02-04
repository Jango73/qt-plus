#ifndef QTPLUS_GLOBAL_H
#define QTPLUS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTPLUS_LIBRARY)
#  define QTPLUSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTPLUSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTPLUS_GLOBAL_H
