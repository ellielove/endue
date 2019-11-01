#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>

#include <QFileDialog>
#include <QMainWindow>
#include <QMouseEvent>

#include <QKeyEvent>
#include <QTextStream>
#include <QTransform>
#include <QUndoStack>

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

#include <../en_lib/src/node_graph_graphics_scene.h>
#include <src/views/node_graph_graphics_view.h>
#include <src/node_graph_expandable_node.h>

namespace Ui {
class MainWindow;
}

class EndueMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndueMainWindow(QWidget *parent = 0);
    ~EndueMainWindow();

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow * ui;
    QPoint m_mouse_pos;

    bool m_show_mouse_pos = true;
    bool createExpandedNodes = false;

    QGraphicsScene * scene;
    NodeGraphGraphicsView * view;


protected:
    // Command actions
    QAction * new_document_action;
    QAction * open_document_action;
    QAction * save_as_document_action;
    QAction * autosave_document_action;
    QAction * exit_program_action;
    QAction * undo_action;
    QAction * redo_action;
    QAction * cut_current_selection_action;
    QAction * copy_current_selection_action;
    QAction * paste_current_selection_action;

    QMenu * file_menu;
    QMenu * edit_menu;

    QUndoStack *undo_stack;


    // Callbacks for command actions
    void create_actions();
    void create_menus();

    void on_triggered__create_new_document();
    void on_triggered__open_existing_document();
    void on_triggered__save_document_as();
    void on_triggered__auto_save_document();
    void on_triggered__exit_program();

    void on_triggered__undo_last_action();
    void on_triggered__redo_last_action();

    void on_triggered__cut_current_selection();
    void on_triggered__copy_current_selection();
    void on_triggered__paste_current_selection();
};

#endif // MAINWINDOW_H
