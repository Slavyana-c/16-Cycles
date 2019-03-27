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
    addstaff.cpp \
    simplecrypt.cpp \
    adminhome.cpp \
    updatestaff.cpp \
    removestaff.cpp \
    resetpassword.cpp \
    profits.cpp \
    createorder.cpp \
    home.cpp \
    updatebikes.cpp \
    addbikes.cpp \
    addbiketypes.cpp \
    removebikes.cpp \
    updateorders.cpp \
    removeorder.cpp \
    statisticsbikes.cpp \
    statisticsshops.cpp

HEADERS  += mainwindow.h \
    addstaff.h \
    simplecrypt.h \
    adminhome.h \
    updatestaff.h \
    removestaff.h \
    resetpassword.h \
    profits.h \
    createorder.h \
    home.h \
    updatebikes.h \
    addbikes.h \
    addbiketypes.h \
    removebikes.h \
    updateorders.h \
    removeorder.h \
    statisticsbikes.h \
    statisticsshops.h

FORMS    += mainwindow.ui \
    addstaff.ui \
    adminhome.ui \
    updatestaff.ui \
    removestaff.ui \
    resetpassword.ui \
    profits.ui \
    createorder.ui \
    home.ui \
    updatebikes.ui \
    addbikes.ui \
    addbiketypes.ui \
    removebikes.ui \
    updateorders.ui \
    removeorder.ui \
    statisticsbikes.ui \
    statisticsshops.ui
    
RESOURCES += \
    resources.qrc
