/// @file Window.cpp
/// @brief Contains the implementation of the Window class in Window.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Window.h"

Window::Window(const char *title, int windowX, int windowY, int width, int height, unsigned int flags) {
    window = SDL_CreateWindow(title, windowX, windowY, width, height, flags);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

unsigned int Window::GetWindowID() {
    return SDL_GetWindowID(window);
}
