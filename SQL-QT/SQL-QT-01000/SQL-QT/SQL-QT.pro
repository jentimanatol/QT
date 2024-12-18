QT += core gui widgets sql network

CONFIG += c++17

# Add the MySQL Connector/C++ library path
LIBS += -L"C:/Program Files/MySQL/MySQL Connector C++ 9.1/lib64/vs14" \
        -lmysqlcppconn -lmysqlcppconnx

# Include directories for MySQL Connector/C++
INCLUDEPATH += "C:/Program Files/MySQL/MySQL Connector C++ 9.1/include" \
               "C:/Program Files/MySQL/MySQL Connector C++ 9.1/include/jdbc"

# Source files
SOURCES += \
    DatabaseManager.cpp \
    ExpenseEntry.cpp \
    IncomeEntry.cpp \
    LogWindow.cpp \
    MenuWindow.cpp \
    TotalBalance.cpp \
    main.cpp \
    widget.cpp

# Header files
HEADERS += \
    DatabaseManager.h \
    ExpenseEntry.h \
    IncomeEntry.h \
    LogWindow.h \
    MenuWindow.h \
    TotalBalance.h \
    widget.h

# UI files
FORMS += \
    ExpensEentry.ui \
    IncomeEntry.ui \
    LogWindow.ui \
    MenuWindow.ui \
    TotalBalance.ui \
    widget.ui
