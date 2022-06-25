QT       += core gui widgets

CONFIG += c++17

include($$PWD/qmysql.pri)

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mysqlconnectiondialog.cpp \
    qmysqlconnectioninfo.cpp \
    qmysqlconnector.cpp

HEADERS += \
    mainwindow.h \
    mysqlconnectiondialog.h \
    qmysqlconnectioninfo.h \
    qmysqlconnector.h

FORMS += \
    mainwindow.ui \
    mysqlconnectiondialog.ui

