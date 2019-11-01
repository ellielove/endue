#include "node_graph_expandable_node.h"

NodeGraphExpandableNode::NodeGraphExpandableNode(bool isExpanded, QGraphicsItem *parent) :
    bIsExpanded(isExpanded),
    QGraphicsItem(parent)
{}

void NodeGraphExpandableNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (bIsExpanded)
    {
        painter->setBrush(selected_a);
        painter->drawEllipse(-100, -50, 200, 100);
    }
    else
    {
        painter->setBrush(notSelected);
        painter->drawEllipse(-10, -10, 20, 20);
    }
}

QRectF NodeGraphExpandableNode::boundingRect() const
{
    if (bIsExpanded)
    {
        return QRectF(-100, -50, 200, 100);
    }
    else
    {
        return QRectF(-10, -10, 20, 20);
    }
}

QPainterPath NodeGraphExpandableNode::shape() const
{}

QPointF NodeGraphExpandableNode::centerPoint() const
{
    return QPointF();
}

void NodeGraphExpandableNode::mousePressEvent(QGraphicsSceneMouseEvent *event)
{}

void NodeGraphExpandableNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{}

void NodeGraphExpandableNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{}

void NodeGraphExpandableNode::setExpanded(bool isExpanded)
{
    this->bIsExpanded = isExpanded;
}

bool NodeGraphExpandableNode::isExpanded() const
{
    return bIsExpanded;
}
