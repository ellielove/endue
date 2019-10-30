#-------------------------------------------------
#
# Project created by QtCreator 2019-10-29T19:18:43
#
#-------------------------------------------------

QT       -= gui

TARGET = en_lib
TEMPLATE = lib

CONFIG += C++14

DEFINES += EN_LIB_LIBRARY
INCLUDEPATH += \
            src \
            src/models \
            src/controllers

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES +=  src/models/client.cpp \
            src/controllers/controller_prime.cpp

HEADERS +=  src/en_lib_global.h \
            src/models/client.h \
            src/controllers/controller_prime.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
