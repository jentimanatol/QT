QT += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testUserLoginProcedure
TEMPLATE = app

SOURCES += main.cpp \
    DatabaseManager.cpp \
           mainwindow.cpp \
           welcomewindow.cpp \
           incomeentry.cpp \
           expenseentry.cpp \
           totalbalance.cpp \


HEADERS += mainwindow.h \
           DatabaseManager.h \
           welcomewindow.h \
           incomeentry.h \
           expenseentry.h \
           totalbalance.h

FORMS += mainwindow.ui \
         incomeentry.ui \
         expenseentry.ui \
         totalbalance.ui \
         welcomewindow.ui
