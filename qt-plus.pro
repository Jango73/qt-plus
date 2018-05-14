
win32 {
    QT += core gui multimedia xml network serialport widgets positioning qml
} else {
    QT += core gui multimedia xml network serialport widgets qml
}

CONFIG += warn_off
TEMPLATE = lib
DEFINES += QTPLUS_LIBRARY

# Uncomment the following to generate QML grammar with Bison
# CONFIG += qml_grammar

INCLUDEPATH += $$PWD/src/cpp/QMLTree
INCLUDEPATH += $$PWD/src/cpp
INCLUDEPATH += $$PWD

qml_grammar {
    PRE_TARGETDEPS += $$PWD/source/cpp/QMLTree/QMLGrammarParser.cpp
    qmlGrammarTarget.target = $$PWD/source/cpp/QMLTree/QMLGrammarParser.cpp
    qmlGrammarTarget.depends = $$PWD/source/bison/QML.y
    qmlGrammarTarget.commands = bison "$$PWD/source/bison/QML.y" -o "$$PWD/source/cpp/QMLTree/QMLGrammarParser.cpp" -g
    QMAKE_EXTRA_TARGETS += qmlGrammarTarget
}

include(qt-plus.pri)

DESTDIR = $$PWD/bin
MOC_DIR = $$PWD/moc/qt-plus
OBJECTS_DIR = $$PWD/obj/qt-plus

QMAKE_CLEAN *= $$DESTDIR/*$$TARGET*
QMAKE_CLEAN *= $$MOC_DIR/*$$TARGET*
QMAKE_CLEAN *= $$OBJECTS_DIR/*$$TARGET*

CONFIG(debug, debug|release) {
    TARGET = qt-plusd
}
CONFIG(release, debug|release) {
    TARGET = qt-plus
}

# Generate help
helpfile = qt-plus.qdocconf

QMAKE_POST_LINK += qdoc $$quote($$shell_path($$helpfile)) $$escape_expand(\\n\\t)

# Copy the index.html to the help directory
copyfile = source/misc/index.html
copydest = help/index.html

QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$shell_path($$copyfile)) $$quote($$shell_path($$copydest)) $$escape_expand(\\n\\t)
