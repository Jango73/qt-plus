
QT += core gui network opengl xml testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console

TEMPLATE = app

# Dependencies
INCLUDEPATH += $$PWD/../source/cpp
DEPENDPATH += $$PWD/../source

# Directories
DESTDIR = $$PWD/../bin
OBJECTS_DIR = $$PWD/obj
MOC_DIR = $$PWD/moc
RCC_DIR = $$PWD/rcc
UI_DIR = $$PWD/ui

# Target
CONFIG(debug, debug|release) {
    TARGET = qt-plus-testd
} else {
    TARGET = qt-plus-test
}

# Libraries
CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/../bin -lqt-plusd
} else {
    LIBS += -L$$PWD/../bin -lqt-plus
}

# Code
SOURCES += \
    source/CUnitTests.cpp

HEADERS += \
    source/CUnitTests.h
