#include <iostream>
#include "Application.h"
#include "OpenGLWindow.h"
#include "SDL2Window.h"

int main() {
    auto *app = new Application();
    app->AddWindow(new OpenGLWindow("OpenGL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
                                    SDL_WINDOW_RESIZABLE));
    app->AddWindow(
            new SDL2Window("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN,
                           -1, SDL_RENDERER_ACCELERATED));
    app->Run();

    // Useless right now since the application will always run until the windows are closed
    app->Quit();
    delete app;
    return 0;
}
