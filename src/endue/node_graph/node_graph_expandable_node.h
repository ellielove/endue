#ifndef NODE_GRAPH_EXPANDABLE_NODE_H
#define NODE_GRAPH_EXPANDABLE_NODE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class NodeGraphExpandableNode : public QGraphicsItem
{
public:
    const QColor notSelected = QColor(102, 159, 250);
    const QColor selected_a = QColor(186, 240, 125);
    const QColor selected_b = QColor(245, 197, 66);

    NodeGraphExpandableNode(bool isExpanded, QGraphicsItem *parent = nullptr);

    // overrides from QGraphicsItem
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    QPointF centerPoint() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void setExpanded(bool isExpanded);
    bool isExpanded() const;

protected:



    bool bIsExpanded = false;
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
