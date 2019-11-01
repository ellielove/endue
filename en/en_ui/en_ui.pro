#-------------------------------------------------
#
# Project created by QtCreator 2019-10-29T19:16:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = en_ui
TEMPLATE = app

CONFIG += C++14

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += src
        ../en_lib/src

SOURCES += src/main.cpp \
        src/views/mainwindow.cpp \
    src/endue_main_window.cpp \
    src/views/node_graph_graphics_view.cpp \
    src/node_graph_expandable_node.cpp

HEADERS += \
        src/views/mainwindow.h \
    src/endue_main_window.h \
    src/views/node_graph_graphics_view.h \
    src/node_graph_expandable_node.h

FORMS += \
        src/mainwindow.ui

RESOURCES += \
    src/views/views.qrc

LIBS += -L$$PWD/../../build-en-Desktop-Debug/en_lib -L en_lib
