QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h

FORMS += mainwindow.ui

DISTFILES += usermanagement.db
