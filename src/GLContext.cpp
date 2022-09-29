/// @file GLContext.cpp
/// @brief Contains the implementation of the GLContext class in GLContext.h
/// @author Jean-Philippe (me\@darkh.app)

#include "GLContext.h"

GLContext::GLContext(const char *title, int windowX, int windowY, int width, int height, unsigned int flags)
        : Window(title, windowX, windowY, width, height, flags | SDL_WINDOW_OPENGL) {
    TTF_Init();

    context = SDL_GL_CreateContext(window);
    projectionMatrix.loadOrthographic(width, height);
    ttfFont = TTF_OpenFont("../assets/fonts/comic.ttf", 24);

    SDL_GL_SetSwapInterval(0);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

GLContext::~GLContext() {
    TTF_CloseFont(ttfFont);
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

void GLContext::drawRectangle(double topLeftX, double topLeftY, double topRightX, double topRightY, double bottomLeftX,
                              double bottomLeftY, double bottomRightX, double bottomRightY) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex2d(topLeftX, topLeftY);
    glTexCoord2d(1, 0);
    glVertex2d(topRightX, topRightY);
    glTexCoord2d(1, 1);
    glVertex2d(bottomRightX, bottomRightY);
    glTexCoord2d(0, 1);
    glVertex2d(bottomLeftX, bottomLeftY);
    glEnd();
}
