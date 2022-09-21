/// @file GLContext.cpp
/// @brief Contains the implementation of the GLContext class in GLContext.h
/// @author Jean-Philippe (me\@darkh.app)

#include "GLContext.h"

GLContext::GLContext(const char *title, int windowX, int windowY, int width, int height, unsigned int flags)
        : Window(title, windowX, windowY, width, height, flags | SDL_WINDOW_OPENGL) {
    context = SDL_GL_CreateContext(window);
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
