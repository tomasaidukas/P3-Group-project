#-------------------------------------------------
#
# Project created by QtCreator 2015-02-03T11:11:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Electrostatics
TEMPLATE = app
LIBS += -L/opt/X11/lib -lX11 -pthread -lm
QMAKE_CXXFLAGS_WARN_ON += -Wno-reorder

SOURCES += main.cpp\
    mainwindow.cpp \
    numerical.cpp \
    mesh.cpp \
    topalg.cpp

HEADERS  += mainwindow.h \
    mesh.h \
    numerical.h \
    topalg.h \
    CImg.h

FORMS    += mainwindow.ui

DISTFILES += \
    PlotPotential.sh \
    eField.cc \
    Plot \
    run.sh

unix {
    #
    # generate the link to the proper version of the ROOT resource file
    #
    rootrc.target = .rootrc
    ROOTRESOURCEFILE=rootrcqtgui
    rootrc.commands = @rm -rf .rootrc; ln -s $$ROOTRESOURCEFILE $$rootrc.target
    QMAKE_EXTRA_TARGETS += rootrc
    PRE_TARGETDEPS += $$rootrc.target
    QMAKE_CLEAN += $$rootrc.target
}
