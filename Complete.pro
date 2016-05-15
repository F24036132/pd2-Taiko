#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T19:22:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Complete
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    explain.cpp

HEADERS  += mainwindow.h \
    explain.h

FORMS    += mainwindow.ui \
    explain.ui

RESOURCES += \
    musics.qrc \
    images.qrc

QT+=multimediawidgets
