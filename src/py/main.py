import random

import pygame
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

# note: this is how you import something in the same level as the script
from src.py.sphere import Sphere
from src.py.cube import Cube
from src.py.cube import Block
from src.py.light import Light


class App(object):
    def __init__(self, width=800, height=600):
        self.title = 'Ellie is getting back to ballet, get the hell off her labes!'
        self.fps = 60
        self.width = width
        self.height = height
        self.angle = 0
        self.distance = 20

        self.game_over = False
        self.random_dt = 0
        self.blocks = []
        self.light = Light(GL_LIGHT0, (0, 15, -25, 1))
        self.player = Sphere(1, position=(0,0,0), color=(0, 1, 0, 1))
        self.ground = Cube(position=(0, -1, -20), scale=(16, 1, 60), color=(1, 1, 1, 1))

        # example positions of objects
        #self.light = Light(GL_LIGHT0, (15, 5, 15, 1))
        #self.sphere1 = Sphere(2, (0, 0, 0), (1, 1, 1, 1))
        #self.sphere2 = Sphere(1, (4, 2, 0), (1, 0.4, 0.4, 1))
        #self.cube1 = Cube((2, 0, 1.5), (1, 1, 1), (1, 1, 1, 1))

    def start(self):
        pygame.init()
        pygame.display.set_mode((self.width, self.height), OPENGL | DOUBLEBUF)
        pygame.display.set_caption(self.title)

        glEnable(GL_DEPTH_TEST)
        self.light.enable()

        glClearColor(.1, .1, .1, .1)
        glMatrixMode(GL_PROJECTION)
        aspect = self.width / self.height
        gluPerspective(40., aspect, 1., 40.)
        glMatrixMode(GL_MODELVIEW)
        glEnable(GL_CULL_FACE)

        self.engine_loop()

    def engine_loop(self):
        eng_clock = pygame.time.Clock()
        while True:
            for event in pygame.event.get():
                if event.type == QUIT:
                    pygame.quit()
                    sys.exit()
            if not self.game_over:
                self.display()
                dt = eng_clock.tick(self.fps)
                for block in self.blocks:
                    block.update(dt)
                self.clear_past_blocks()
                self.add_random_block(dt)
                self.check_collision()
                self.process_input(dt)

    def check_collision(self):
        blocks = filter(lambda x: 0 < x.position[2] < 1, self.blocks)
        x = self.player.position[0]
        r = self.player.radius
        for block in blocks:
            x1 = block.position[0]
            s = block.size / 2
            if x1-s < x-r < x1+s or x1-s < x+r < x1+s:
                self.game_over = True
                print("Game Over!")

    def add_random_block(self, dt):
        self.random_dt += dt
        if self.random_dt >= 800:
            r = random.random()
            if r < 0.1:
                self.random_dt = 0
                self.generate_block(r)

    def generate_block(self, r):
        size = 7 if r < 0.03 else 5
        offset = random.choice([-4, 0, 4])
        self.blocks.append(Block((offset, 0, -40), size))

    def clear_past_blocks(self):
        blocks = filter(lambda x: x.position[2] > 5, self.blocks)
        for block in blocks:
            self.blocks.remove(block)
            del block

    def process_input(self, dt):
        keypress = pygame.key.get_pressed()
        x, y, z = self.player.position
        if keypress[K_LEFT]:
            x -= 0.01 * dt
        if keypress[K_RIGHT]:
            x += 0.01 * dt
        x = max(min(x, 7), -7)
        self.player.position = (x, y, z)

    def display(self):
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glLoadIdentity()
        gluLookAt(
            0, 10, 10,
            0, 0, -5,
            0, 1, 0)

        self.light.render()

        for block in self.blocks:
            block.render()

        self.player.render()
        self.ground.render()

        pygame.display.flip()

    def quit(self):
        pygame.quit()
        sys.exit()


if __name__ == '__main__':
    a = App()
    a.start()

