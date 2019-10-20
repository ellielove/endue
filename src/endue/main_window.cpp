#include "main_window.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->create_actions();
    this->create_menus();
    this->setMouseTracking(true);

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    view->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
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

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Down; Button# " << event->button();

    QPointF pos = event->pos();
    qreal rad = 20;

    auto ellipse = scene->addEllipse(-rad, -rad, rad * 2.0, rad * 2.0);
    ellipse->setPos(pos);
    ellipse->setVisible(true);

    qDebug() << "scene->items() = " << scene->items().count();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Up; Button# " << event->button();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
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

void MainWindow::create_actions()
{
    // NOTE: Keep actions in alphabetical order

    // Autosave
    //const QIcon autoSaveIcon = QIcon::fromTheme("document-auto-save", QIcon(":/images/auto-save.png"))
    autosave_document_action = new QAction(tr("&Autosave"), this);
    autosave_document_action->setShortcuts(QKeySequence::Save);
    autosave_document_action->setStatusTip(tr("Automatically save this file after elapsed time"));
    connect(autosave_document_action, &QAction::triggered, this, &MainWindow::auto_save_document);

    // Copy
    //const QIcon copyIcon = QIcon::fromTheme("document-copy", QIcon(":/images/copy.png"))
    copy_current_selection_action = new QAction(tr("&Copy"), this);
    copy_current_selection_action->setShortcuts(QKeySequence::Copy);
    copy_current_selection_action->setStatusTip(tr("Copies current selection"));
    connect(copy_current_selection_action, &QAction::triggered, this, &MainWindow::copy_current_selection);

    // Cut
    //const QIcon cutIcon = QIcon::fromTheme("document-cut", QIcon(":/images/cut.png"))
    cut_current_selection_action = new QAction(tr("&Cut"), this);
    cut_current_selection_action->setShortcuts(QKeySequence::Cut);
    cut_current_selection_action->setStatusTip(tr("Cuts out the current selection"));
    connect(cut_current_selection_action, &QAction::triggered, this, &MainWindow::cut_current_selection);

    // Exit
    //const QIcon exitProgramIcon = QIcon::fromTheme("document-exit-program", QIcon(":/images/exit-program.png"))
    exit_program_action = new QAction(tr("&Exit Program"), this);
    exit_program_action->setShortcuts(QKeySequence::Quit);
    exit_program_action->setStatusTip(tr("Close the Endue program"));
    connect(exit_program_action, &QAction::triggered, this, &MainWindow::exit_program);

    // New
    //const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"))
    new_document_action = new QAction(tr("&New"), this);
    new_document_action->setShortcuts(QKeySequence::New);
    new_document_action->setStatusTip(tr("Create a new file"));
    connect(new_document_action, &QAction::triggered, this, &MainWindow::create_new_document);

    // Open
    //const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/images/open.png"))
    open_document_action = new QAction(tr("&Open"), this);
    open_document_action->setShortcuts(QKeySequence::Open);
    open_document_action->setStatusTip(tr("Open an existing file"));
    connect(open_document_action, &QAction::triggered, this, &MainWindow::open_existing_document);

    // Paste
    //const QIcon pasteIcon = QIcon::fromTheme("document-paste", QIcon(":/images/paste.png"))
    paste_current_selection_action = new QAction(tr("&Paste"), this);
    paste_current_selection_action->setShortcuts(QKeySequence::Paste);
    paste_current_selection_action->setStatusTip(tr("Pastes current selection"));
    connect(paste_current_selection_action, &QAction::triggered, this, &MainWindow::paste_current_selection);

    // Redo
    //const QIcon redoIcon = QIcon::fromTheme("document-redo", QIcon(":/images/redo.png"))
    redo_action = new QAction(tr("&Redo"), this);
    redo_action->setShortcuts(QKeySequence::Redo);
    redo_action->setStatusTip(tr("Redo last action"));
    connect(redo_action, &QAction::triggered, this, &MainWindow::redo_last_action);

    // Save As
    //const QIcon saveAsIcon = QIcon::fromTheme("document-save-as", QIcon(":/images/save-as.png"))
    save_as_document_action = new QAction(tr("&Save As"), this);
    save_as_document_action->setShortcuts(QKeySequence::SaveAs);
    save_as_document_action->setStatusTip(tr("Save current work to new file"));
    connect(save_as_document_action, &QAction::triggered, this, &MainWindow::save_document_as);

    // Undo
    //const QIcon undoIcon = QIcon::fromTheme("document-undo", QIcon(":/images/undo.png"))
    undo_action = new QAction(tr("&Undo"), this);
    undo_action->setShortcuts(QKeySequence::Undo);
    undo_action->setStatusTip(tr("Undo last action"));
    connect(undo_action, &QAction::triggered, this, &MainWindow::undo_last_action);
}


void MainWindow::create_menus()
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
