#include "endue_main_window.h"
#include "ui_mainwindow.h"

EndueMainWindow::EndueMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->create_actions();
    this->create_menus();
    this->setMouseTracking(true);

    scene = new QGraphicsScene(this);
    view = new NodeGraphGraphicsView(scene, this);

    view->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->setCentralWidget(view);
}

EndueMainWindow::~EndueMainWindow()
{
    delete ui;
}

void EndueMainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_show_mouse_pos)
    {
        QPoint pos = event->pos();
        QString qstr;
        QTextStream(&qstr) << "mouse: (" << pos.x() << ", " << pos.y() << ")";
        ui->statusBar->showMessage(qstr, 0);
    }
    else
    {
        ui->statusBar->showMessage("", 0);
    }
}

void EndueMainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Down; Button# " << event->button();

    QPointF pos = event->pos();
    qreal rad = 20;

    // contains the right offset for current ellipse
    const auto ellipseRect = QRectF(-rad, -rad * 3.0, rad * 2.0, rad * 2.0);
    auto ellipse = scene->addEllipse(ellipseRect);
    ellipse->setPos(pos);
    ellipse->setVisible(true);

    qDebug() << "scene->items() = " << scene->items().count();
}
void EndueMainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Up; Button# " << event->button();
}

void EndueMainWindow::keyPressEvent(QKeyEvent *event)
{
    Qt::Key key = static_cast<Qt::Key>(event->key());
    if (key == Qt::Key_Escape)
    {
        this->close();
    }
    if (key == Qt::Key_Space){}
    if (key == Qt::Key_1){ m_show_mouse_pos = !m_show_mouse_pos; }
    if (key == Qt::Key_2){}
    if (key == Qt::Key_3){}
    if (key == Qt::Key_4){}
}

void EndueMainWindow::create_actions()
{
    // NOTE: Keep actions in alphabetical order

    // Autosave
    //const QIcon autoSaveIcon = QIcon::fromTheme("document-auto-save", QIcon(":/images/auto-save.png"))
    autosave_document_action = new QAction(tr("&Autosave"), this);
    autosave_document_action->setShortcuts(QKeySequence::Save);
    autosave_document_action->setStatusTip(tr("Automatically save this file after elapsed time"));
    connect(autosave_document_action, &QAction::triggered, this, &EndueMainWindow::on_triggered__auto_save_document);

    // Copy
    //const QIcon copyIcon = QIcon::fromTheme("document-copy", QIcon(":/images/copy.png"))
    copy_current_selection_action = new QAction(tr("&Copy"), this);
    copy_current_selection_action->setShortcuts(QKeySequence::Copy);
    copy_current_selection_action->setStatusTip(tr("Copies current selection"));
    connect(copy_current_selection_action, &QAction::triggered, this, &EndueMainWindow::on_triggered__copy_current_selection);

    // Cut
    //const QIcon cutIcon = QIcon::fromTheme("document-cut", QIcon(":/images/cut.png"))
    cut_current_selection_action = new QAction(tr("&Cut"), this);
    cut_current_selection_action->setShortcuts(QKeySequence::Cut);
    cut_current_selection_action->setStatusTip(tr("Cuts out the current selection"));
    connect(cut_current_selection_action, &QAction::triggered, this, &EndueMainWindow::on_triggered__cut_current_selection);

    // Exit
    //const QIcon exitProgramIcon = QIcon::fromTheme("document-exit-program", QIcon(":/images/exit-program.png"))
    exit_program_action = new QAction(tr("&Exit Program"), this);
    exit_program_action->setShortcuts(QKeySequence::Quit);
    exit_program_action->setStatusTip(tr("Close the Endue program"));
    connect(exit_program_action, &QAction::triggered, this, &EndueMainWindow::on_triggered__exit_program);

    // New
    //const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"))
    new_document_action = new QAction(tr("&New"), this);
    new_document_action->setShortcuts(QKeySequence::New);
    new_document_action->setStatusTip(tr("Create a new file"));
    connect(new_document_action, &QAction::triggered, this, &EndueMainWindow::on_triggered__create_new_document);

    // Open
    //const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/images/open.png"))
    open_document_action = new QAction(tr("&Open"), this);
    open_document_action->setShortcuts(QKeySequence::Open);
    open_document_action->setStatusTip(tr("Open an existing file"));
    connect(open_document_action, &QAction::triggered, this, &EndueMainWindow::on_triggered__open_existing_document);

    // Paste
    //const QIcon pasteIcon = QIcon::fromTheme("document-paste", QIcon(":/images/paste.png"))
    paste_current_selection_action = new QAction(tr("&Paste"), this);
    paste_current_selection_action->setShortcuts(QKeySequence::Paste);
    paste_current_selection_action->setStatusTip(tr("Pastes current selection"));
    connect(paste_current_selection_action, &QAction::triggered, this, &EndueMainWindow::on_triggered__paste_current_selection);

    // Redo
    //const QIcon redoIcon = QIcon::fromTheme("document-redo", QIcon(":/images/redo.png"))
    redo_action = new QAction(tr("&Redo"), this);
    redo_action->setShortcuts(QKeySequence::Redo);
    redo_action->setStatusTip(tr("Redo last action"));
    connect(redo_action, &QAction::triggered, this, &EndueMainWindow::on_triggered__redo_last_action);

    // Save As
    //const QIcon saveAsIcon = QIcon::fromTheme("document-save-as", QIcon(":/images/save-as.png"))
    save_as_document_action = new QAction(tr("&Save As"), this);
    save_as_document_action->setShortcuts(QKeySequence::SaveAs);
    save_as_document_action->setStatusTip(tr("Save current work to new file"));
    connect(save_as_document_action, &QAction::triggered, this, &EndueMainWindow::on_triggered__save_document_as);

    // Undo
    //const QIcon undoIcon = QIcon::fromTheme("document-undo", QIcon(":/images/undo.png"))
    undo_action = new QAction(tr("&Undo"), this);
    undo_action->setShortcuts(QKeySequence::Undo);
    undo_action->setStatusTip(tr("Undo last action"));
    connect(undo_action, &QAction::triggered, this, &EndueMainWindow::on_triggered__undo_last_action);
}


void EndueMainWindow::create_menus()
{
    file_menu = menuBar()->addMenu(tr("&File"));
    file_menu->addAction(new_document_action);
    file_menu->addAction(open_document_action);
    file_menu->addAction(save_as_document_action);
    file_menu->addAction(autosave_document_action);
    file_menu->addSeparator();
    file_menu->addAction(exit_program_action);

    edit_menu = menuBar()->addMenu(tr("&Edit"));
    edit_menu->addAction(undo_action);
    edit_menu->addAction(redo_action);
    edit_menu->addSeparator();
    edit_menu->addAction(cut_current_selection_action);
    edit_menu->addAction(copy_current_selection_action);
    edit_menu->addAction(paste_current_selection_action);
    //edit_menu->addSeparator();
}

void EndueMainWindow::on_triggered__create_new_document()
{
    qDebug() << "create_new_document";

    // recipe:
    //    ask for save
    //    reset QGraphicsScene
    //    reset QGraphicsView
}

void EndueMainWindow::on_triggered__open_existing_document()
{
    qDebug() << "open_existing_document";

    // GTK runs at a lower level than Qt, and a GTK window doesn't have a
    // concept of a Qt window, therefore, we can't provide a Qt parent
    // window to GTK.
    //
    // Here, we manually control the file dialog, and toggle on/off the
    // system native window when using linux
    //
    // QFileDialog documentation  --  https://doc.qt.io/qt-5/qfiledialog.html
    // Problem documentation -- https://forum.qt.io/topic/85997/gtk-warning-for-native-qfiledialog-under-linux
    QFileDialog dialog(this, tr("Open File"));
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("Endue (*.end)"));
    dialog.setViewMode(QFileDialog::Detail);


// TODO: Put the OS define somewhere else
#define LINUX = 1
#ifdef LINUX
    // NOTE: If we use the native dialog in linux, then we get the warning:
    // "Gtk-Message: <timestamp>: GtkDialog mapped without a transient parent. This is discouraged."
    dialog.setOption(QFileDialog::DontUseNativeDialog);
#endif

    // Should only ever return one file, cause we're using: QFileDialog::ExistingFile
    QStringList fileNames;
    if (dialog.exec())
    {
        fileNames = dialog.selectedFiles();
    }


    // TODO: remove once better testing is in place
    if(fileNames.length() < 1)
    {
        ui->statusBar->showMessage(tr("No file selected"), 0);
    }
    else
    {
        ui->statusBar->showMessage(fileNames[0], 0);
    }
}

void EndueMainWindow::on_triggered__save_document_as()
{
    qDebug() << "save_document_as";

    // recipe
    //    Open save dialog
    //    Get file path from dialog
    //    Check path (just in case)
    //    Write to path
}


void EndueMainWindow::on_triggered__auto_save_document(){qDebug()<<"auto_save_document";}

void EndueMainWindow::on_triggered__exit_program()
{
    qDebug()<<"exit_program";
    exit(0);
}

void EndueMainWindow::on_triggered__undo_last_action(){qDebug()<<"undo_last_action";}
void EndueMainWindow::on_triggered__redo_last_action(){qDebug()<<"redo_last_action";}
void EndueMainWindow::on_triggered__cut_current_selection(){qDebug()<<"cut_current_selection";}
void EndueMainWindow::on_triggered__copy_current_selection(){qDebug()<<"copy_current_selection";}
void EndueMainWindow::on_triggered__paste_current_selection(){qDebug()<<"paste_current_selection";}
