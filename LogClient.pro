#-------------------------------------------------
#
# Project created by QtCreator 2014-09-17T23:01:12
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LogClient
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    logclient.cpp

HEADERS  += dialog.h \
    logclient.h

FORMS    += dialog.ui
