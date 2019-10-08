#ifndef NODE_GRAPH_GRAPHICS_VIEW_H
#define NODE_GRAPH_GRAPHICS_VIEW_H

#include <QGraphicsView>

class NodeGraphGraphicsView : public QGraphicsView
{
public:
    NodeGraphGraphicsView(QWidget *parent = nullptr) : QGraphicsView(parent){}
    NodeGraphGraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr) : QGraphicsView(scene, parent){}

};

#endif // NODE_GRAPH_GRAPHICS_VIEW_H
