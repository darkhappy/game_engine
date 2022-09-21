/// @file GLContext.cpp
/// @brief Contains the implementation of the GLContext class in GLContext.h
/// @author Jean-Philippe (me\@darkh.app)

#include "GLContext.h"

GLContext::GLContext(const char *title, int windowX, int windowY, int width, int height, unsigned int flags)
        : Window(title, windowX, windowY, width, height, flags | SDL_WINDOW_OPENGL) {
    context = SDL_GL_CreateContext(window);
    projectionMatrix.loadOrthographic(width, height);
}

GLContext::~GLContext() {
    SDL_GL_DeleteContext(context);
}

void GLContext::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void GLContext::update() {
    SDL_GL_SwapWindow(window);
}

void GLContext::draw() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMultMatrixd(projectionMatrix.elements);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor4d(1, 0, 0, 1);
    glVertex3d(50, 50, 0);
    glVertex3d(50, 100, 0);
    glVertex3d(100, 100, 0);
    glVertex3d(100, 50, 0);
    glEnd();
}
