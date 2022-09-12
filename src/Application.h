//
// Created by Jean-Philippe on 2022-09-07.
//

#ifndef SDL_LIBRARY_APPLICATION_H
#define SDL_LIBRARY_APPLICATION_H

#include <vector>
#include <SDL2/SDL.h>
#include "Window.h"
#include "Event.h"

class Application {
private:
    std::vector<Window *> windows;
public:
    Application();

    ~Application();

    void AddWindow(Window *window);

    void Run();

    void Quit();
};


#endif //SDL_LIBRARY_APPLICATION_H
