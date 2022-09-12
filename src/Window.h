//
// Created by Jean-Philippe on 2022-09-07.
//

#ifndef SDL_LIBRARY_WINDOW_H
#define SDL_LIBRARY_WINDOW_H

#include <SDL2/SDL.h>

class Window {
protected:
    SDL_Window *window;
public:
    Window(const char *title, int width, int height, unsigned int flags);
    virtual ~Window() = 0;
    virtual void Clear() = 0;
    virtual void Update() = 0;
};


#endif //SDL_LIBRARY_WINDOW_H