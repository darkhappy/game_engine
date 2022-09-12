//
// Created by Jean-Philippe on 2022-09-07.
//

#ifndef SDL_LIBRARY_OPENGLWINDOW_H
#define SDL_LIBRARY_OPENGLWINDOW_H

#include <SDL2/SDL_opengl.h>
#include "Window.h"

class OpenGLWindow : public Window {
private:
    SDL_GLContext context;
public:
    OpenGLWindow(const char *title, int windowX, int windowY, int width, int height, unsigned int flags);
    ~OpenGLWindow() override;
    void Clear() override;
    void Update() override;
};


#endif //SDL_LIBRARY_OPENGLWINDOW_H
