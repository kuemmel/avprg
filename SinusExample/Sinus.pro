#-------------------------------------------------
#
# Project created by QtCreator 2014-08-04T12:43:08
#
#-------------------------------------------------

QT       += core gui widgets multimedia


TARGET = Sinus
TEMPLATE = app

INCLUDEPATH += ../audioengine
SOURCES += main.cpp\
        mainwindow.cpp\
        oscillatorsource.cpp\
    sources/sinus.cpp \
    sources/noise.cpp \
    sources/rect.cpp \
    sources/tent.cpp \
    sources/sawtooth.cpp \
    sources/source.cpp \
    note.cpp \
    envelope.cpp \
    midicontrol.cpp \
    audiocontrol.cpp

HEADERS  += mainwindow.h \
    oscillatorsource.h\
    sources/sinus.h \
    sources/source.h \
    sources/noise.h \
    sources/rect.h \
    sources/tent.h \
    sources/sawtooth.h \
    note.h \
    envelope.h \
    midicontrol.h \
    audiocontrol.h


FORMS    += mainwindow.ui

#QMAKE_CXXFLAGS +=  -std=c++11

include(../audioengine/audioplayer.pri)
include(../drumstick/drumstick.pro)
