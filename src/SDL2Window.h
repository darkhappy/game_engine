/// @file SDL2Window.h
/// @brief Contains a window, rendered using SDL2
/// @author Jean-Philippe (me\@darkh.app)

#ifndef SDL_LIBRARY_SDL2WINDOW_H
#define SDL_LIBRARY_SDL2WINDOW_H

#include "Window.h"

/// @class SDL2Window
/// @brief Represents a window using SDL2
class SDL2Window : public Window {
private:
    SDL_Renderer *renderer; ///< The renderer
public:
    /// @brief Creates a window
    /// @param title The title of the window, by default "SDL2 Window"
    /// @param windowX The x position of the window
    /// @param windowY The y position of the window
    /// @param width The width of the window
    /// @param height The height of the window
    /// @param flags The flags of the window, see SDL_CreateWindow() for more information
    /// @param index The index of the renderer, see SDL_CreateRenderer() for more information. By default, -1 is used
    /// @param rendererFlags The flags of the renderer, see SDL_CreateRenderer() for more information. By default, 0 is used
    /// @see SDL_CreateWindow()
    /// @see SDL_CreateRenderer()
    explicit SDL2Window(const char *title = "SDL2 Window", int windowX = SDL_WINDOWPOS_CENTERED,
                        int windowY = SDL_WINDOWPOS_CENTERED, int width = 1280, int height = 720,
                        unsigned int flags = 0, int index = -1, unsigned int rendererFlags = 0);

    /// @brief Destroys the window
    ~SDL2Window() override;

    /// @brief Clears the window
    void Clear() override;

    /// @brief Updates the window
    void Update() override;
};

#endif //SDL_LIBRARY_SDL2WINDOW_H
