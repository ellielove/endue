
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *


class Sphere(object):
    slices = 40
    stacks = 40

    def __init__(self, radius, position, color):
        self.radius = radius
        self.position = position
        self.color = color

    def render(self):
        glPushMatrix()
        glTranslatef(*self.position)
        glMaterialfv(GL_FRONT, GL_DIFFUSE, self.color)
        glutSolidSphere(self.radius, Sphere.slices, Sphere.stacks)
        glPopMatrix()
