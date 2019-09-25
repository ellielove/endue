
import sys
import math

import pygame
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

# note: this is how you import something in the same level as the script
from src.sphere import Sphere
from src.cube import Cube
from src.light import Light


class App(object):
    def __init__(self, width=800, height=600):
        self.title = 'Ellie is getting back to ballet, get the hell off her labes!'
        self.fps = 60
        self.width = width
        self.height = height
        self.angle = 0
        self.distance = 20

        self.light = Light(GL_LIGHT0, (15, 5, 15, 1))
        self.sphere1 = Sphere(2, (0, 0, 0), (1, 1, 1, 1))
        self.sphere2 = Sphere(1, (4, 2, 0), (1, 0.4, 0.4, 1))
        self.cube1 = Cube((2, 0, 1.5), (1, 1, 1), (1, 1, 1, 1))

    def start(self):
        pygame.init()
        pygame.display.set_mode((self.width, self.height), OPENGL | DOUBLEBUF)
        pygame.display.set_caption(self.title)

        #glEnable(GL_LIGHTING)
        glEnable(GL_CULL_FACE)
        glEnable(GL_DEPTH_TEST)
        self.light.enable()

        glClearColor(.1, .1, .1, .1)
        glMatrixMode(GL_PROJECTION)
        aspect = self.width / self.height
        gluPerspective(40., aspect, 1., 40.)
        glMatrixMode(GL_MODELVIEW)

        eng_clock = pygame.time.Clock()
        while True:
            dt = eng_clock.tick(self.fps)
            self.process_input(dt)
            self.display()

    def process_input(self, dt):
        for event in pygame.event.get():
            if event.type == QUIT:
                self.quit()
            if event.type == KEYDOWN:
                if event.key == K_ESCAPE:
                    self.quit()
                if event.key == K_F1:
                    self.light.switch_color()

        keypress = pygame.key.get_pressed()
        if keypress[K_UP]:
            self.distance -= 0.01 * dt
        if keypress[K_DOWN]:
            self.distance += 0.01 * dt
        if keypress[K_LEFT]:
            self.angle -= 0.005 * dt
        if keypress[K_RIGHT]:
            self.angle += 0.005 * dt

        self.distance = max(10, min(self.distance, 20))
        self.angle %= math.pi * 2

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
        self.cube1.render()
        pygame.display.flip()

    def quit(self):
        pygame.quit()
        sys.exit()


if __name__ == '__main__':
    a = App()
    a.start()

