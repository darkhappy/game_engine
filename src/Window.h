/// @file Window.h
/// @brief Contains the class that represents a window
/// @author Jean-Philippe (me\@darkh.app)

#ifndef SDL_LIBRARY_WINDOW_H
#define SDL_LIBRARY_WINDOW_H

#include <SDL2/SDL.h>

/// @class Window
/// @brief Represents a window
class Window {
protected:
    SDL_Window *window; ///< The window

    /// @brief Creates a window
    /// @param title The title of the window, by default "Window"
    /// @param windowX The x position of the window, by default SDL_WINDOWPOS_CENTERED
    /// @param windowY The y position of the window, by default SDL_WINDOWPOS_CENTERED
    /// @param width The width of the window, by default 1280
    /// @param height The height of the window, by default 720
    /// @param flags The flags of the window, see SDL_CreateWindow() for more information
    /// @see SDL_CreateWindow()
    explicit Window(const char *title = "Window", int windowX = SDL_WINDOWPOS_CENTERED,
                    int windowY = SDL_WINDOWPOS_CENTERED,
                    int width = 1280, int height = 720, unsigned int flags = 0);

public:
    /// @brief Destroys the window
    virtual ~Window() = 0;

    /// @brief Clears the window
    virtual void clear() = 0;

    /// @brief Updates the window
    virtual void update() = 0;
};


#endif //SDL_LIBRARY_WINDOW_H
