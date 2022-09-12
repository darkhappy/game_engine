//
// Created by Jean-Philippe on 2022-09-08.
//

#ifndef SDL_LIBRARY_EVENT_H
#define SDL_LIBRARY_EVENT_H

#include <SDL2/SDL.h>

class Event {
private:
    static SDL_Event event;
public:
    static int PollEvent();
    static unsigned int GetEventType();
};


#endif //SDL_LIBRARY_EVENT_H
