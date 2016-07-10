#-------------------------------------------------
#
# Project created by QtCreator 2016-07-10T15:29:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lf2_Qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stageselect.cpp \
    gameitem.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    stageselect.h \
    gameitem.h \
    player.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
