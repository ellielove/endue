#ifndef NODE_GRAPH_EXPANDABLE_NODE_H
#define NODE_GRAPH_EXPANDABLE_NODE_H

#include <QGraphicsItem>

class NodeGraphExpandableNode : public QGraphicsItem
{
public:
    NodeGraphExpandableNode();

    // overrides from QGraphicsItem
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;


    QColor base_color;
    // position in 2d space
    // position in 3d space?
    // isExpanded
    // expand animation (and in reverse)

    // when expanded, shows more info
    // when not, shows name

    // states: selected, not-selected; expanded, not-expanded
    // use style sheet

    // node keeps track of many connections
    // node can only display the top 0<=N<=10 connections

    // if this node is a definition-head

};

#endif // NODE_GRAPH_EXPANDABLE_NODE_H
