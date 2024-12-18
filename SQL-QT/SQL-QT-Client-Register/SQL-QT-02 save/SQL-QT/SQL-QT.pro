QT += core gui widgets sql

CONFIG += c++11

# Add the MySQL Connector/C++ library path
LIBS += -L"C:/Program Files/MySQL/MySQL Connector C++ 9.1/lib64/vs14" -lmysqlcppconn -lmysqlcppconnx

# Include directories for MySQL Connector/C++
INCLUDEPATH += "C:/Program Files/MySQL/MySQL Connector C++ 9.1/include"
INCLUDEPATH += "C:/Program Files/MySQL/MySQL Connector C++ 9.1/include/jdbc"

SOURCES += \
    DatabaseManager.cpp \
    ExpenseEntry.cpp \
    IncomeEntry.cpp \
    LogWindow.cpp \
    MenuWindow.cpp \
    TotalBalance.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    DatabaseManager.h \
    ExpenseEntry.h \
    IncomeEntry.h \
    LogWindow.h \
    MenuWindow.h \
    TotalBalance.h \
    widget.h

FORMS += \
    ExpensEentry.ui \
    IncomeEntry.ui \
    LogWindow.ui \
    MenuWindow.ui \
    TotalBalance.ui \
    widget.ui
