//
// Created by Jean-Philippe on 2022-09-07.
//

#include "OpenGLWindow.h"

OpenGLWindow::OpenGLWindow(const char *title, int width, int height, unsigned int flags) : Window(title, width, height,
                                                                                                  flags |
                                                                                                  SDL_WINDOW_OPENGL) {
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
