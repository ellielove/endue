
import math
import uuid

from PyQt5.QtCore import (qrand, QRectF, QPointF, Qt)
from PyQt5.QtGui import (QBrush, QLinearGradient, QPainter)

from PyQt5.QtWidgets import (QGraphicsScene, QGraphicsView)

from node_graphics_item import Node
from edge_graphics_item import Edge


class GraphWidget(QGraphicsView):
    def __init__(self):
        super(GraphWidget, self).__init__()

        self.timerId = 0
        self.nodes = None

        scene = QGraphicsScene(self)
        scene.setItemIndexMethod(QGraphicsScene.NoIndex)
        scene.setSceneRect(-200, -200, 400, 400)
        self.setScene(scene)
        self.setCacheMode(QGraphicsView.CacheBackground)
        self.setViewportUpdateMode(QGraphicsView.BoundingRectViewportUpdate)
        self.setRenderHint(QPainter.Antialiasing)
        self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        self.setResizeAnchor(QGraphicsView.AnchorViewCenter)

        self.add_node(-50, -50, 'one')
        self.add_node(  0, -50, 'two')
        self.add_node( 50, -50, 'three')
        self.add_node(-50,   0, 'four')
        self.add_node(  0,   0, 'five')
        self.add_node( 50,   0, 'six')
        self.add_node(-50,  50, 'seven')
        self.add_node(  0,  50, 'eight')
        self.add_node( 50,  50, 'nine')

        one   = self.get_node('one')
        two   = self.get_node('two')
        three = self.get_node('three')
        four  = self.get_node('four')
        five  = self.get_node('five')
        six   = self.get_node('six')
        seven = self.get_node('seven')
        eight = self.get_node('eight')
        nine  = self.get_node('nine')

        self.add_edge(one, two)
        self.add_edge(two, three)
        self.add_edge(two, five)
        self.add_edge(three, six)
        self.add_edge(four, one)
        self.add_edge(four, five)
        self.add_edge(five, six)
        self.add_edge(five, eight)
        self.add_edge(six, nine)
        self.add_edge(seven, four)
        self.add_edge(eight, seven)
        self.add_edge(nine, eight)

        self.scale(0.8, 0.8)
        self.setMinimumSize(400, 400)
        #self.setWindowTitle("Elastic Nodes")

    def refresh_nodes(self):
        self.nodes = [item for item in self.scene().items() if isinstance(item, Node)]

    def get_node(self, name):
        if self.nodes is None:
            self.refresh_nodes()
        for node in self.nodes[:]:
            if node.name is name:
                return node
        return None

    def add_node(self, x, y, name=None):
        node = Node(self, name)
        node.setPos(QPointF(float(x), float(y)))
        self.scene().addItem(node)

    def add_edge(self, source_node, destination_node):
        edge = Edge(source_node, destination_node)
        self.scene().addItem(edge)

    def item_moved(self):
        if not self.timerId:
            self.timerId = self.startTimer(1000 / 25)

    def keyPressEvent(self, event):
        key = event.key()

        if key == Qt.Key_Escape:
            exit(0)
        elif key == Qt.Key_Up:
            self.centerNode.moveBy(0, -20)
        elif key == Qt.Key_Down:
            self.centerNode.moveBy(0, 20)
        elif key == Qt.Key_Left:
            self.centerNode.moveBy(-20, 0)
        elif key == Qt.Key_Right:
            self.centerNode.moveBy(20, 0)
        elif key == Qt.Key_Plus:
            self.scale_view(1.2)
        elif key == Qt.Key_Minus:
            self.scale_view(1 / 1.2)
        elif key == Qt.Key_Space or key == Qt.Key_Enter:
            for item in self.scene().items():
                if isinstance(item, Node):
                    item.setPos(-150 + qrand() % 300, -150 + qrand() % 300)
        else:
            super(GraphWidget, self).keyPressEvent(event)

    def mousePressEvent(self, event):
        bttn = event.button()

        if bttn == Qt.LeftButton:
            pos = event.pos()
            self.add_node(pos.x(), pos.y(), uuid.uuid4())

        pass

    def timerEvent(self, event):
        nodes = [item for item in self.scene().items() if isinstance(item, Node)]

        for node in nodes:
            node.calculate_forces()

        itemsMoved = False
        for node in nodes:
            if node.advance():
                itemsMoved = True

        if not itemsMoved:
            self.killTimer(self.timerId)
            self.timerId = 0

    def wheelEvent(self, event):
        self.scale_view(math.pow(2.0, -event.angleDelta().y() / 240.0))

    def drawBackground(self, painter, rect):
        # Shadow.
        sceneRect = self.sceneRect()
        rightShadow = QRectF(sceneRect.right(), sceneRect.top() + 5, 5,
                             sceneRect.height())
        bottomShadow = QRectF(sceneRect.left() + 5, sceneRect.bottom(),
                              sceneRect.width(), 5)
        if rightShadow.intersects(rect) or rightShadow.contains(rect):
            painter.fillRect(rightShadow, Qt.darkGray)
        if bottomShadow.intersects(rect) or bottomShadow.contains(rect):
            painter.fillRect(bottomShadow, Qt.darkGray)

        # Fill.
        gradient = QLinearGradient(sceneRect.topLeft(), sceneRect.bottomRight())
        gradient.setColorAt(0, Qt.white)
        gradient.setColorAt(1, Qt.lightGray)
        painter.fillRect(rect.intersected(sceneRect), QBrush(gradient))
        painter.setBrush(Qt.NoBrush)
        painter.drawRect(sceneRect)

        # Text.
        textRect = QRectF(sceneRect.left() + 4, sceneRect.top() + 4,
                          sceneRect.width() - 4, sceneRect.height() - 4)
        message = "Click and drag the nodes around, and zoom with the " \
                  "mouse wheel or the '+' and '-' keys"

        font = painter.font()
        font.setBold(True)
        font.setPointSize(14)
        painter.setFont(font)
        painter.setPen(Qt.lightGray)
        #painter.drawText(textRect.translated(2, 2), message)
        painter.setPen(Qt.black)
        #painter.drawText(textRect, message)

    def scale_view(self, scale_factor):
        factor = self.transform().scale(scale_factor, scale_factor).mapRect(QRectF(0, 0, 1, 1)).width()

        if factor < 0.07 or factor > 100:
            return

        self.scale(scale_factor, scale_factor)
