/// @file GLContext.h
/// @brief Contains a window, rendered using OpenGL
/// @author Jean-Philippe (me\@darkh.app)

#ifndef SDL_LIBRARY_GLCONTEXT_H
#define SDL_LIBRARY_GLCONTEXT_H

#include <SDL2/SDL_opengl.h>
#include "Window.h"

/// @class GLContext
/// @brief Represents a window using OpenGL
class GLContext : public Window {
private:
    SDL_GLContext context; ///< The context
public:
    /// @brief Creates a window
    /// @param title The title of the window, by default "OpenGL Window"
    /// @param windowX The x position of the window
    /// @param windowY The y position of the window
    /// @param width The width of the window
    /// @param height The height of the window
    /// @param flags The flags of the window, see SDL_CreateWindow() for more information. By default, SDL_WINDOW_OPENGL is added to the flags
    /// @see SDL_CreateWindow()
    explicit GLContext(const char *title = "OpenGL Window", int windowX = SDL_WINDOWPOS_CENTERED,
                       int windowY = SDL_WINDOWPOS_CENTERED, int width = 1280, int height = 720,
                       unsigned int flags = 0);

    /// @brief Destroys the window
    ~GLContext() override;

    /// @brief Clears the window
    void clear() override;

    /// @brief Updates the window
    void update() override;
};


#endif //SDL_LIBRARY_GLCONTEXT_H