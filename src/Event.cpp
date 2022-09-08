//
// Created by Jean-Philippe on 2022-09-08.
//

#include "Event.h"

SDL_Event Event::event;

int Event::PollEvent() {
    return SDL_PollEvent(&event);
}

unsigned int Event::GetEventType() {
    return event.type;
}
