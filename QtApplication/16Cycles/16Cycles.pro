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
    editdb.cpp \
    staff.cpp \
    addstaff.cpp \
    simplecrypt.cpp

HEADERS  += mainwindow.h \
    home.h \
    editdb.h \
    staff.h \
    addstaff.h \
    simplecrypt.h

FORMS    += mainwindow.ui \
    home.ui \
    editdb.ui \
    staff.ui \
    addstaff.ui

RESOURCES += \
    resources.qrc
