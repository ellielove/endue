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
    src/endue_main_window.cpp \
    src/node_graph/node_graph_expandable_node.cpp \
    src/node_graph/node_graph_graphics_scene.cpp \
    src/node_graph/node_graph_graphics_view.cpp

HEADERS += \
    src/endue_main_window.h \
    src/node_graph/node_graph_expandable_node.h \
    src/node_graph/node_graph_graphics_scene.h \
    src/node_graph/node_graph_graphics_view.h

FORMS += \
        src/mainwindow.ui

RESOURCES += \

LIBS += -L$$PWD/../../build-en-Desktop-Debug/en_lib -L en_lib
