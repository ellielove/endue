#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QMouseEvent>

#include <QKeyEvent>
#include <QTextStream>
#include <QUndoStack>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

//#include <node_graph/node_graph_graphics_scene.h>
//#include<node_graph/node_graph_graphics_view.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QPoint m_mouse_pos;
    bool m_show_mouse_pos = true;

    QGraphicsScene *scene;
    QGraphicsView *view;

    QAction *new_document_action;
    QAction *open_document_action;
    QAction *save_as_document_action;
    QAction *autosave_document_action;
    QAction *exit_program_action;
    QAction *undo_action;
    QAction *redo_action;
    QAction *cut_current_selection_action;
    QAction *copy_current_selection_action;
    QAction *paste_current_selection_action;

    QMenu *file_menu;
    QMenu *edit_menu;

    QUndoStack *undo_stack;

    void create_actions();
    void create_menus();

    void create_new_document(){qDebug() << "create_new_document";};
    void open_existing_document(){qDebug() << "open_existing_document";};
    void save_document_as(){qDebug() << "save_as_document";};
    void auto_save_document(){qDebug() << "auto_save_document";};
    void exit_program(){qDebug() << "exit_program";};

    void undo_last_action(){qDebug() << "undo_last_action";};
    void redo_last_action(){qDebug() << "redo_last_action";};

    void cut_current_selection(){qDebug() << "cut_current_selection";};
    void copy_current_selection(){qDebug() << "copy_current_selection";};
    void paste_current_selection(){qDebug() << "paste_current_selection";};
};

#endif // MAINWINDOW_H
