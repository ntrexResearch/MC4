#-------------------------------------------------
#
# Project created by QtCreator 2017-07-13T09:16:20
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MC4
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    tab.cpp \
    connectiontab.cpp \
    diotab.cpp \
    monitortab.cpp \
    jogtab.cpp \
    xaxistab.cpp \
    yaxistab.cpp \
    zaxistab.cpp \
    haxistab.cpp \
    axistab.cpp \
    motiontab.cpp \
    controlstatusgrid.cpp \
    table1tab.cpp \
    tabletab.cpp \
    table2tab.cpp \
    table3tab.cpp \
    table4tab.cpp \
    table5tab.cpp \
    table6tab.cpp \
    table7tab.cpp \
    table8tab.cpp \
    table9tab.cpp \
    table10tab.cpp \
    tablebuttongrid.cpp

HEADERS += \
        mainwindow.h \
    tab.h \
    connectiontab.h \
    diotab.h \
    monitortab.h \
    jogtab.h \
    xaxistab.h \
    yaxistab.h \
    zaxistab.h \
    haxistab.h \
    axistab.h \
    motiontab.h \
    controlstatusgrid.h \
    table1tab.h \
    tabletab.h \
    table2tab.h \
    table3tab.h \
    table4tab.h \
    table5tab.h \
    table6tab.h \
    table7tab.h \
    table8tab.h \
    table9tab.h \
    table10tab.h \
    tablebuttongrid.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    images.qrc
