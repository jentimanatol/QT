QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoopbackExample
TEMPLATE = app

SOURCES += main.cpp \
           dialog.cpp

HEADERS += dialog.h

FORMS += dialog.ui
