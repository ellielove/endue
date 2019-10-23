#-------------------------------------------------
#
# Project created by QtCreator 2019-09-26T20:20:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = endue
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    node_graph/node_graph_graphics_scene.cpp \
    node_graph/node_graph_graphics_view.cpp \
    node_graph/node_graph_expandable_node.cpp \
    node_graph/node_graph_edge.cpp \
    endue_main_window.cpp

HEADERS += \
    ui/drawable_node.h \
    node_graph/node_graph_graphics_scene.h \
    node_graph/node_graph_graphics_view.h \
    node_graph/node_graph_expandable_node.h \
    node_graph/node_graph_edge.h \
    endue_main_window.h


FORMS += \
        mainwindow.ui

RESOURCES += \
    resources.qrc
