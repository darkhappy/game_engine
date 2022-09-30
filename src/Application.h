/// @file Application.h
/// @brief Contains the declaration of the Application class
/// @author Jean-Philippe (me\@darkh.app)

#ifndef SDL_LIBRARY_APPLICATION_H
#define SDL_LIBRARY_APPLICATION_H

#include "Chronometer.h"
#include "GLContext.h"
#include "Singleton.h"

/// @class Application
/// @brief Represents an application
class Application : public Singleton<Application> {
private:
    GLContext context;         ///< The window that the app is running, see Window for more information
    int fps{};                 ///< The fps of the application
    Chronometer fpsChronometer;///< The chronometer used to calculate the fps
public:
    /// @brief Creates an application
    Application();

    /// @brief Destroys the application
    ~Application();

    /// @brief Starts the application
    void start();
};

#endif//SDL_LIBRARY_APPLICATION_H
