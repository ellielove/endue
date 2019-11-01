#-------------------------------------------------
#
# Project created by QtCreator 2019-10-29T19:20:14
#
#-------------------------------------------------

QT       += testlib
QT       -= gui

TARGET = tst_client_tests
TEMPLATE = app

CONFIG   += C++14
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += \
    src
    ../en_lib/src

SOURCES += \
    main.cpp \
    test_suite.cpp \
    src/controllers/controller_prime_tests.cpp

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    test_suite.h \
    src/controllers/controller_prime_tests.h

LIBS += -L$$PWD/../../build-en-Desktop-Debug/en_lib -l en_lib
