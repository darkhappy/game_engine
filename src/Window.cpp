/// @file Window.cpp
/// @brief Contains the implementation of the Window class in Window.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Window.h"

Window::Window(const char *title, int windowX, int windowY, int width, int height, unsigned int flags) {
    window = SDL_CreateWindow(title, windowX, windowY, width, height, flags);
    this->width = width;
    this->height = height;
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

int Window::getWidth() const {
    return width;
}

int Window::getHeight() const {
    return height;
}
