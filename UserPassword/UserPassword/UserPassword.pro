QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    loginscreen.cpp \
    user.cpp \
    superuser.cpp \
    encryption.cpp

HEADERS += \
    loginscreen.h \
    user.h \
    superuser.h \
    encryption.h

FORMS += \
    loginscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
