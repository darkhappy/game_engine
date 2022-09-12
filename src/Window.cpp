//
// Created by Jean-Philippe on 2022-09-07.
//

#include "Window.h"

Window::Window(const char *title, int windowX, int windowY, int width, int height, unsigned int flags) {
    window = SDL_CreateWindow(title, windowX, windowY, width, height, flags);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}
