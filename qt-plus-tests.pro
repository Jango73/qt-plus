#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T15:40:48
#
#-------------------------------------------------

QT += gui xml network serialport positioning qml quickwidgets

CONFIG   += console

TEMPLATE = app

SOURCES += \
    source/cpp/Test/tests-main.cpp \
    source/cpp/Test/ParsingMonitor.cpp

HEADERS += \
    source/cpp/Test/tests-main.h \
    source/cpp/Test/ParsingMonitor.h

DEPENDPATH += qt-plus

DESTDIR = $$PWD/bin
MOC_DIR = $$PWD/moc/qt-plus-tests
OBJECTS_DIR = $$PWD/obj/qt-plus-tests

QMAKE_CLEAN *= $$DESTDIR/*$$TARGET*
QMAKE_CLEAN *= $$MOC_DIR/*$$TARGET*
QMAKE_CLEAN *= $$OBJECTS_DIR/*$$TARGET*

CONFIG(debug, debug|release) {
    TARGET = qt-plus-testsd
    LIBS += -L$$PWD/bin/ -lqt-plusd
} else {
    TARGET = qt-plus-tests
    LIBS += -L$$PWD/bin/ -lqt-plus
}
