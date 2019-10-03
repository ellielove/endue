#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMouseTracking(true);
    ui->centralWidget->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();

    if (debug_mode)
    {
        qDebug() << "Mouse: " << pos;
    }

    QString str;
    QTextStream(&str) << "mouse: (" << pos.x() << ", " << pos.y() << ")";
    ui->statusBar->showMessage(str, 0);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (debug_mode)
    {
        qDebug() << "Mouse Down; Button# " << event->button();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (debug_mode)
    {
        qDebug() << "Mouse Up; Button# " << event->button();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    Qt::Key key = static_cast<Qt::Key>(event->key());
    if (key == Qt::Key_Escape)
    {
        this->close();
    }
    if (key == Qt::Key_Space)
    {
        // expand current node?
    }
}
