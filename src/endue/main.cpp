
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

//#include "mainwindow.h"
#include "ui/drawablenode.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.setWindowTitle(QString("Endue"));
    //w.show();


    QGraphicsScene scene;

    DrawableNode *circleItem = new DrawableNode(QRect(0, 50, 25, 25));
    scene.addItem(circleItem);

    QGraphicsView view(&scene);
    view.show();

    return a.exec();
}
