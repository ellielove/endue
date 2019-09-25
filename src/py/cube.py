
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *


class Cube(object):
    sides = ((0, 1, 2, 3), (3, 2, 7, 6), (6, 7, 5, 4),
             (4, 5, 1, 0), (1, 5, 7, 2), (4, 0, 3, 6))

    def __init__(self, position, scale, color):
        self.position = position
        self.color = color
        x, y, z = map(lambda i: i/2, scale)
        self.verticies = (
            (x, -y, -z), (x, y, -z),
            (-x, y, -z), (-x, -y, -z),
            (x, -y, z), (x, y, z),
            (-x, -y, z), (-x, y, z))

    def render(self):
        glPushMatrix()
        glTranslatef(*self.position)
        glBegin(GL_QUADS)
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, self.color)
        for side in Cube.sides:
            for v in side:
                glVertex3fv(self.verticies[v])
        glEnd()
        glPopMatrix()


class Block(Cube):
    color = (0, 0, 1, 1)
    speed = 0.01

    def __init__(self, position, size):
        super().__init__(position, (size, 1, 1), Block.color)
        self.size = size

    def update(self, dt):
        x, y, z = self.position
        z += Block.speed * dt
        self.position = x, y, z
