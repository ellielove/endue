#ifndef NODE_GRAPH_GRAPHICS_VIEW_H
#define NODE_GRAPH_GRAPHICS_VIEW_H

#include <QGraphicsView>

class NodeGraphGraphicsView : public QGraphicsView
{
private:
    const QRectF DEFAULT_SCENE_RECT = QRectF(0, 0, 4000, 4000);

public:
    explicit NodeGraphGraphicsView(QWidget *parent = nullptr);
    explicit NodeGraphGraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);
};

#endif // NODE_GRAPH_GRAPHICS_VIEW_H
