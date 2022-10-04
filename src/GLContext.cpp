/// @file GLContext.cpp
/// @brief Contains the implementation of the GLContext class in GLContext.h
/// @author Jean-Philippe (me\@darkh.app)

#include "GLContext.h"

GLContext::GLContext(const char *title, int windowX, int windowY, int width, int height, unsigned int flags)
        : Window(title, windowX, windowY, width, height, flags | SDL_WINDOW_OPENGL) {
    TTF_Init();

    context = SDL_GL_CreateContext(window);
    projectionMatrix.loadOrthographic(width, height);

    SDL_GL_SetSwapInterval(0);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
}

void GLContext::drawRectangle(Vector3d position, Vector3d size) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);
        glTexCoord2d(0, 0); glVertex2d(position.x, position.y);
        glTexCoord2d(1, 0); glVertex2d(position.x + size.x, position.y);
        glTexCoord2d(1, 1); glVertex2d(position.x + size.x, position.y + size.y);
        glTexCoord2d(0, 1); glVertex2d(position.x, position.y + size.y);
    glEnd();
}

void GLContext::drawFont(const TTFont &font, Vector3d position) {
    font.bind();
    GLContext::drawRectangle(position, Vector3d(font.getWidth(), font.getHeight()));
    TTFont::unbind();
}
