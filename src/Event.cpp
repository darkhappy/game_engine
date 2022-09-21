/// @file Event.cpp
/// @brief Contains the implementation of the Event class in Event.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Event.h"

SDL_Event Event::event;

int Event::poll() {
    return SDL_PollEvent(&event);
}

unsigned int Event::getEventType() {
    return event.type;
}
