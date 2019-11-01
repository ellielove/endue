#ifndef NODE_GRAPH_GRAPHICS_VIEW_H
#define NODE_GRAPH_GRAPHICS_VIEW_H

#include <QDebug>

#include <QMouseEvent>
#include <QGraphicsView>

#include <src/node_graph/node_graph_expandable_node.h>

class NodeGraphGraphicsView : public QGraphicsView
{
private:
    const QRectF DEFAULT_SCENE_RECT = QRectF(0, 0, 4000, 4000);

public:
    explicit NodeGraphGraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    //void createNode(const QPointF position, qreal radius);
};

#endif // NODE_GRAPH_GRAPHICS_VIEW_H
