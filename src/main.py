
import sys
import math

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

# note: this is how you import something in the same level as the script
from src.sphere import Sphere
from src.light import Light


class App(object):
    def __init__(self, width=800, height=600):
        self.title = b'OpenGL demo'
        self.width = width
        self.height = height
        self.angle = 0
        self.distance = 20

        self.light = Light(GL_LIGHT0, (15, 5, 15, 1))
        self.sphere1 = Sphere(2, (0, 0, 0), (1, 1, 1, 1))
        self.sphere2 = Sphere(1, (4, 2, 0), (1, 0.4, 0.4, 1))

    def start(self):
        glutInit()
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH)
        glutInitWindowPosition(50, 50)
        glutInitWindowSize(self.width, self.height)
        glutCreateWindow(self.title)

        glEnable(GL_DEPTH_TEST)
        self.light.enable()

        glClearColor(.1, .1, .1, .1)
        glMatrixMode(GL_PROJECTION)
        aspect = self.width / self.height
        gluPerspective(40., aspect, 1., 40.)
        glMatrixMode(GL_MODELVIEW)

        glutDisplayFunc(self.display)
        glutSpecialFunc(self.keyboard)
        glutMainLoop()

    def keyboard(self, key, x, y):
        if key == GLUT_KEY_INSERT:
            sys.exit(0)
        if key == GLUT_KEY_UP:
            self.distance -= 0.1
        if key == GLUT_KEY_DOWN:
            self.distance += 1
        if key == GLUT_KEY_LEFT:
            self.angle -= 0.05
        if key == GLUT_KEY_RIGHT:
            self.angle += 0.05
        if key == GLUT_KEY_F1:
            self.light.switch_color()
        self.distance = max(10, min(self.distance, 20))
        self.angle %= math.pi * 2
        glutPostRedisplay()

    def display(self):
        x = math.sin(self.angle) * self.distance
        z = math.cos(self.angle) * self.distance

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glLoadIdentity()
        gluLookAt(
            x, 0, z,
            0, 0, 0,
            0, 1, 0)

        self.light.render()
        self.sphere1.render()
        self.sphere2.render()
        glutSwapBuffers()


if __name__ == '__main__':
    a = App()
    a.start()

