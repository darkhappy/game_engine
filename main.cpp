#include <iostream>
#include "Application.h"
#include "OpenGLWindow.h"
#include "SDL2Window.h"

int main() {
    auto *app = new Application();
    app->AddWindow(new OpenGLWindow("OpenGL Window", 800, 600, SDL_WINDOW_OPENGL));
    app->AddWindow(new SDL2Window("SDL2 Window", 800, 600, SDL_WINDOW_SHOWN));
    app->Run();
    return 0;
}
