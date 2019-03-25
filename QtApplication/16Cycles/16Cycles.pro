#-------------------------------------------------
#
# Project created by QtCreator 2019-03-23T20:00:23
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 16Cycles
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    home.cpp \
    editdb.cpp

HEADERS  += mainwindow.h \
    home.h \
    editdb.h

FORMS    += mainwindow.ui \
    home.ui \
    editdb.ui

RESOURCES += \
    resources.qrc
