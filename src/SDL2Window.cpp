/// @file SDL2Window.cpp
/// @brief Contains the implementation of the SDL2Window class in SDL2Window.h
/// @author Jean-Philippe (me\@darkh.app)

#include "SDL2Window.h"

SDL2Window::SDL2Window(const char *title, int windowX, int windowY, int width, int height, unsigned int flags,
                       int index, unsigned int rendererFlags) : Window(title, windowX, windowY, width, height, flags) {
    renderer = SDL_CreateRenderer(window, index, rendererFlags);
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