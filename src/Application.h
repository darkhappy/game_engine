/// @file Application.h
/// @brief Contains the declaration of the Application class
/// @author Jean-Philippe (me\@darkh.app)

#ifndef SDL_LIBRARY_APPLICATION_H
#define SDL_LIBRARY_APPLICATION_H

#include <SDL2/SDL.h>
#include "GLContext.h"
#include "Event.h"

/// @class Application
/// @brief Represents an application
class Application {
private:
    GLContext context; ///< The window that the app is running, see Window for more information
    static Application instance; ///< The instance of the application

    /// @brief Creates an application
    Application();

public:

    /// @brief Destroys the application
    ~Application();

    /// @brief Gets the instance of the application
    /// @return The instance of the application
    static Application &GetInstance();

    /// @brief Runs the application
    void start();
};

#endif //SDL_LIBRARY_APPLICATION_H
