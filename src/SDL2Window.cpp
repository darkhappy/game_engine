//
// Created by Jean-Philippe on 2022-09-07.
//

#include "SDL2Window.h"


SDL2Window::SDL2Window(const char *title, int width, int height, unsigned int flags) : Window(title, width, height,
                                                                                              flags) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL2Window::~SDL2Window() {
    SDL_DestroyRenderer(renderer);
}

void SDL2Window::Clear() {
    SDL_RenderClear(renderer);
}

void SDL2Window::Update() {
    SDL_SetRenderDrawColor(renderer, 255, 155, 155, 255);
    SDL_RenderPresent(renderer);
}
