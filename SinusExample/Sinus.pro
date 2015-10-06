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
    sinus.cpp \
    noise.cpp \
    rect.cpp \
    tent.cpp \
    sawtooth.cpp \
    source.cpp \
    note.cpp \
    envelope.cpp

HEADERS  += mainwindow.h \
    oscillatorsource.h\
    sinus.h \
    source.h \
    noise.h \
    rect.h \
    tent.h \
    sawtooth.h \
    note.h \
    envelope.h

FORMS    += mainwindow.ui

#QMAKE_CXXFLAGS +=  -std=c++11

include(../audioengine/audioplayer.pri)
