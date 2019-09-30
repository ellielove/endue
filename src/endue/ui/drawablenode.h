#ifndef DRAWABLENODE_H
#define DRAWABLENODE_H

#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>

class DrawableNode : public QGraphicsEllipseItem
{
private:
    const QColor notSelected = QColor(102, 159, 250);
    const QColor selected_a = QColor(186, 240, 125);
    const QColor selected_b = QColor(245, 197, 66);

    float half_width;
    float half_height;

public:
    DrawableNode(QRect Rect) : QGraphicsEllipseItem(Rect)
    {
        setFlag(QGraphicsEllipseItem::ItemIsMovable);
        setFlag(QGraphicsEllipseItem::ItemIsSelectable);

        this->setBrush(QBrush(notSelected));

        half_width = Rect.width() * 0.5;
        half_height = Rect.height() * 0.5;
    }



    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        QPointF pos = event->pos();
        if (event->button() == Qt::LeftButton)
        {
            qDebug() << "LMB";
            setSelected(true);
            this->setBrush(QBrush(selected_a));
        }
        else if (event->button() == Qt::RightButton)
        {
            qDebug() << "RMB";
            this->setBrush(QBrush(selected_b));
        }

        qDebug() << "isSelected: " << this->isSelected();
    }

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
    {
        setSelected(false);
        this->setBrush(QBrush(notSelected));
        qDebug() << "isSelected: " << this->isSelected();
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        if(this->isSelected())
        {
            QRectF next_rect = this->rect();
            // subtract out the half-lengths to move the center of the node
            next_rect.moveTo(event->pos() - QPoint(half_width, half_height));
            this->setRect(next_rect);
        }
    }

};


#endif // DRAWABLENODE_H
