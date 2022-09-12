/// @file OpenGLWindow.cpp
/// @brief Contains the implementation of the OpenGLWindow class in OpenGLWindow.h
/// @author Jean-Philippe (me\@darkh.app)

#include "OpenGLWindow.h"

OpenGLWindow::OpenGLWindow(const char *title, int windowX, int windowY, int width, int height, unsigned int flags)
        : Window(title, windowX, windowY, width, height, flags | SDL_WINDOW_OPENGL) {
    context = SDL_GL_CreateContext(window);
}

OpenGLWindow::~OpenGLWindow() {
    SDL_GL_DeleteContext(context);
}

void OpenGLWindow::Clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLWindow::Update() {
    SDL_GL_SwapWindow(window);
}
