#ifndef QTPLUS_GLOBAL_H
#define QTPLUS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTPLUS_LIBRARY)
#  define QTPLUSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTPLUSSHARED_EXPORT Q_DECL_IMPORT
#endif

// qt-plus version, keep in sync with VERSION in qt-plus.pro
// and project(VERSION) in CMakeLists.txt
#define QTPLUS_VERSION_MAJOR 3
#define QTPLUS_VERSION_MINOR 0
#define QTPLUS_VERSION_PATCH 0
#define QTPLUS_VERSION_STR "3.0.0"
#define QTPLUS_VERSION QT_VERSION_CHECK(QTPLUS_VERSION_MAJOR, QTPLUS_VERSION_MINOR, QTPLUS_VERSION_PATCH)

#endif // QTPLUS_GLOBAL_H
