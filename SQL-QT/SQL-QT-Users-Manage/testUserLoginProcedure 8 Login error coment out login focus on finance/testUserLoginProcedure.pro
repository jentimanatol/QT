QT += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testUserLoginProcedure
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp \
           incomeentry.cpp \
           expenseentry.cpp \
           totalbalance.cpp \
           userforgotpass.cpp \
           userregister.cpp \
           welcome.cpp

HEADERS += mainwindow.h \
           incomeentry.h \
           expenseentry.h \
           totalbalance.h \
           userforgotpass.h \
           userregister.h \
           welcome.h

FORMS += mainwindow.ui \
         incomeentry.ui \
         expenseentry.ui \
         totalbalance.ui \
         welcome.ui \
         userforgotpass.ui \
         userregister.ui
