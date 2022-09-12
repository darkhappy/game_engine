/// @file Event.h
/// @brief Contains information about events
/// @author Jean-Philippe (me\@darkh.app)

#ifndef SDL_LIBRARY_EVENT_H
#define SDL_LIBRARY_EVENT_H

#include <SDL2/SDL.h>

/// @class Event
/// @brief Contains information about events
class Event {
private:
    /// @brief The event
    static SDL_Event event;
public:
    /// @brief Gets information about the next event
    /// @return 1 if there is an event, 0 if there is no event, -1 if there is an error
    static int PollEvent();

    /// @brief Gets the event type
    /// @return The event type
    static unsigned int GetEventType();
};

#endif //SDL_LIBRARY_EVENT_H
