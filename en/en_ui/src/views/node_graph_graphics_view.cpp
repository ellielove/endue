#include "node_graph_graphics_view.h"


//NodeGraphGraphicsView::NodeGraphGraphicsView(QWidget *parent) :
//    QGraphicsView(parent)
//{}

NodeGraphGraphicsView::NodeGraphGraphicsView(QGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene, parent)
{
    this->setSceneRect(DEFAULT_SCENE_RECT);
}

void NodeGraphGraphicsView::mousePressEvent(QMouseEvent *event)
{
    qDebug() << this->itemAt(event->pos());

    QGraphicsView::mousePressEvent(event);
}

void NodeGraphGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

void NodeGraphGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
}

///void NodeGraphGraphicsView::createNode(const QPointF position, qreal radius)
///{
///    //auto node = new NodeGraphExpandableNode(createExpandedNodes);
///    //node->setPos(position);
///    //scene->addItem(node);
///    ///// contains the right offset for current ellipse
///    ///const auto ellipseRect = QRectF(
///    ///      -radius
///    ///    , -radius * 3.0
///    ///    ,  radius * 2.0
///    ///    ,  radius * 2.0
///    ///);
///}
