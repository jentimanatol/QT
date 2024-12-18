QT += core gui sql

CONFIG += c++17

LIBS += -L"C:/Program Files/MySQL/MySQL Connector C++ 9.1/lib64/vs14" -lmysqlcppconn -lmysqlcppconnx

INCLUDEPATH += "C:/Program Files/MySQL/MySQL Connector C++ 9.1/include"
INCLUDEPATH += "C:/Program Files/MySQL/MySQL Connector C++ 9.1/include/jdbc"

SOURCES += \
    main.cpp \
    DatabaseManager.cpp \
    LogWindow.cpp

HEADERS += \
    DatabaseManager.h \
    LogWindow.h

FORMS += \
    LogWindow.ui \
    widget.ui
