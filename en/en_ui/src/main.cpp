
#include <QApplication>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <../en_ui/src/endue_main_window.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EndueMainWindow w;
    w.setWindowTitle(EndueMainWindow::tr("Endue"));
    w.show();

    return a.exec();
}
