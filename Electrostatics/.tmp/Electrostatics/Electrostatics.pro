#-------------------------------------------------
#
# Project created by QtCreator 2015-02-03T11:11:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Electrostatics
TEMPLATE = app

CONFIG = dist


SOURCES += main.cpp\
    mainwindow.cpp \
    numerical.cpp \
    mesh.cpp \
    topalg.cpp

HEADERS  += mainwindow.h \
    numerical.h \
    CImg.h \
    mesh.h \
    topalg.h

FORMS    += mainwindow.ui

DISTFILES += \
    numPlot
