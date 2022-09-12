//
// Created by Jean-Philippe on 2022-09-07.
//

#ifndef SDL_LIBRARY_SDL2WINDOW_H
#define SDL_LIBRARY_SDL2WINDOW_H

#include "Window.h"

class SDL2Window : public Window {
private:
    SDL_Renderer *renderer;
public:
    SDL2Window(const char *title, int windowX, int windowY, int width, int height, unsigned int flags, int index = -1,
               unsigned int rendererFlags = 0);

    ~SDL2Window() override;

    void Clear() override;

    void Update() override;
};


#endif //SDL_LIBRARY_SDL2WINDOW_H
