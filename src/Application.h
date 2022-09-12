/// @file Application.h
/// @brief Contains the declaration of the Application class
/// @author Jean-Philippe (me\@darkh.app)

#ifndef SDL_LIBRARY_APPLICATION_H
#define SDL_LIBRARY_APPLICATION_H

#include <map>
#include <SDL2/SDL.h>
#include "Window.h"
#include "Event.h"

/// @class Application
/// @brief Represents an application
class Application {
private:
    std::map<unsigned int, Window *> windows; ///< The windows, see Window for more information
public:
    /// @brief Creates an application
    Application();

    /// @brief Destroys the application
    ~Application();

    /// @brief Adds a window to the application
    /// @param window The window to add
    void AddWindow(Window *window);

    /// @brief Runs the application
    void Run();

    /// @brief Quits the application
    void Quit();

    /// @brief Removes a window from the application
    /// @param windowID The window to remove
    void RemoveWindow(unsigned int windowID);
};

#endif //SDL_LIBRARY_APPLICATION_H
