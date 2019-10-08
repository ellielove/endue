#ifndef NODE_GRAPH_GRAPHICS_SCENE_H
#define NODE_GRAPH_GRAPHICS_SCENE_H

#include <QGraphicsScene>

class NodeGraphGraphicsScene : public QGraphicsScene
{
public:
    // https://en.wikipedia.org/wiki/C++11#Explicitly_defaulted_and_deleted_special_member_functions
    //NodeGraphGraphicsScene & operator=(const NodeGraphGraphicsScene&) = delete;
    //NodeGraphGraphicsScene(const NodeGraphGraphicsScene&) = delete;
    NodeGraphGraphicsScene(QObject *parent = nullptr) : QGraphicsScene(parent)
    {}
};

#endif // NODE_GRAPH_GRAPHICS_SCENE_H
