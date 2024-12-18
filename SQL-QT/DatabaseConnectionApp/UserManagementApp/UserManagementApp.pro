QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
           DatabaseManager.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h \
    DatabaseManager.h \
    User.h \
    UserLogin.h

FORMS += mainwindow.ui

DISTFILES += usermanagement.db
