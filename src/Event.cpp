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

int Event::getMouseButton() {
    return event.button.button;
}

int Event::getMouseX() {
    return event.button.x;
}

int Event::getMouseY() {
    return event.button.y;
}
