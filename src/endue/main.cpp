
#include <QApplication>
#include "endue_main_window.h"

#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EndueMainWindow w;
    w.setWindowTitle(EndueMainWindow::tr("Endue"));
    w.show();

    return a.exec();
}
