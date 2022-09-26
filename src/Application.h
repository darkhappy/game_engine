/// @file Application.h
/// @brief Contains the declaration of the Application class
/// @author Jean-Philippe (me\@darkh.app)

#ifndef SDL_LIBRARY_APPLICATION_H
#define SDL_LIBRARY_APPLICATION_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GLContext.h"
#include "Singleton.h"
#include "Event.h"

/// @class Application
/// @brief Represents an application
class Application : public Singleton<Application> {
private:
    GLContext context; ///< The window that the app is running, see Window for more information

public:

    /// @brief Creates an application
    Application();

    /// @brief Destroys the application
    ~Application();

    /// @brief Runs the application
    void start();
};

#endif //SDL_LIBRARY_APPLICATION_H
