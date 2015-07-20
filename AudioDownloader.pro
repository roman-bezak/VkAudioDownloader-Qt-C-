#-------------------------------------------------
#
# Project created by QtCreator 2015-07-07T12:37:52
#
#-------------------------------------------------

QT       += core gui webkitwidgets network
QT +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AudioDownloader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    downloader.cpp \
    oauth.cpp \
    getsender.cpp \
    requestmanager.cpp \
    audiomanager.cpp \
    json.cpp \
    track.cpp \
    downloadqueue.cpp \
    traksrepository.cpp

HEADERS  += mainwindow.h \
    downloader.h \
    oauth.h \
    getsender.h \
    requestmanager.h \
    audiomanager.h \
    json.h \
    track.h \
    downloadqueue.h \
    traksrepository.h

FORMS    += mainwindow.ui \
    audiomanager.ui \
    downloadqueue.ui
