//
// Created by Jean-Philippe on 2022-09-07.
//

#include "Window.h"

Window::Window(const char *title, int width, int height, unsigned int flags) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}
