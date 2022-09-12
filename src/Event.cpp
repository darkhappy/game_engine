/// @file Event.cpp
/// @brief Contains the implementation of the Event class in Event.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Event.h"

SDL_Event Event::event;

int Event::PollEvent() {
    return SDL_PollEvent(&event);
}

unsigned int Event::GetEventType() {
    return event.type;
}

unsigned int Event::GetWindowEventType() {
    return event.window.event;
}

unsigned int Event::GetWindowID() {
    return event.window.windowID;
}