
#include <QApplication>
#include "main_window.h"


#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle(MainWindow::tr("Endue"));
    w.show();

    return a.exec();
}
