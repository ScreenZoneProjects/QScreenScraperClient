#-------------------------------------------------
#
# Project created by QtCreator 2015-11-11T18:03:29
#
#-------------------------------------------------

QT       += network sql

QT       -= gui

TARGET = QScreenScraperAPIClient
TEMPLATE = lib

DEFINES += QSCREENSCRAPERAPICLIENT_LIBRARY

SOURCES += QScreenScraperAPIClient.cpp \
    CHeader.cpp \
    CResponse.cpp \
    CRequest.cpp

HEADERS += QScreenScraperAPIClient.hpp\
        qscreenscraperapiclient_global.hpp \
    CHeader.hpp \
    CResponse.hpp \
    CRequest.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
