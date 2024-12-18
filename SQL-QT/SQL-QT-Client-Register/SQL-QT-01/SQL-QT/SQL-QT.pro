QT += core gui widgets sql

CONFIG += c++11

# Add the MySQL Connector/C++ library path
LIBS += -L"C:/Program Files/MySQL/MySQL Connector C++ 9.1/lib64/vs14" -lmysqlcppconn -lmysqlcppconnx

# Include directories for MySQL Connector/C++
INCLUDEPATH += "C:/Program Files/MySQL/MySQL Connector C++ 9.1/include"
INCLUDEPATH += "C:/Program Files/MySQL/MySQL Connector C++ 9.1/include/jdbc"

SOURCES += \
    loginwindow.cpp \
    main.cpp


HEADERS += \
    loginwindow.h


FORMS += \
    loginwindow.ui

