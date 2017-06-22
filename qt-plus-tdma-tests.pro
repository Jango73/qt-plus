#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T15:40:48
#
#-------------------------------------------------

QT += gui xml network serialport positioning qml quickwidgets

CONFIG   += console

TEMPLATE = app

SOURCES += \
    source/cpp/Test/TDMATest.cpp \
    source/cpp/Test/SingleChannelDevice.cpp \
    source/cpp/Test/SingleChannelDeviceRelay.cpp

HEADERS += \
    source/cpp/Test/TDMATest.h \
    source/cpp/Test/SingleChannelDevice.h \
    source/cpp/Test/SingleChannelDeviceRelay.h

DEPENDPATH += qt-plus

DESTDIR = $$PWD/bin
MOC_DIR = $$PWD/moc/qt-plus-tdma-tests
OBJECTS_DIR = $$PWD/obj/qt-plus-tdma-tests

QMAKE_CLEAN *= $$DESTDIR/*$$TARGET*
QMAKE_CLEAN *= $$MOC_DIR/*$$TARGET*
QMAKE_CLEAN *= $$OBJECTS_DIR/*$$TARGET*

CONFIG(debug, debug|release) {
    TARGET = qt-plus-tdma-testsd
    LIBS += -L$$PWD/bin/ -lqt-plusd
} else {
    TARGET = qt-plus-tdma-tests
    LIBS += -L$$PWD/bin/ -lqt-plus
}
