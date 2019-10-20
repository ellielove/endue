#include "node_graph_graphics_view.h"


NodeGraphGraphicsView::NodeGraphGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
}

NodeGraphGraphicsView::NodeGraphGraphicsView(QGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene, parent)
{
    this->setSceneRect(DEFAULT_SCENE_RECT);
}
