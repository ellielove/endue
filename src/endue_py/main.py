
from PyQt5.QtCore import (qsrand, QTime)

from PyQt5.QtWidgets import QApplication

from graph_widget import GraphWidget


if __name__ == '__main__':
    import sys

    app = QApplication(sys.argv)
    app.setApplicationName('Endue')

    qsrand(QTime(0, 0, 0).secsTo(QTime.currentTime()))

    widget = GraphWidget()
    widget.show()

    sys.exit(app.exec_())