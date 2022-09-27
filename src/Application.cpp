/// @file Application.cpp
/// @brief Contains the implementation of the Application class in Application.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Application.h"

Application::Application() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    fps = 0;
}

Application::~Application() = default;

void Application::start() {
    bool running = true;
    fpsChronometer.startChronometer();

    Chronometer textureChronometer;
    textureChronometer.startChronometer();

    Texture *brick = new Texture("../assets/images/brick.png");
    Texture *vim = new Texture("../assets/images/vim.png");

    vim->bind();

    while (running) {
        while (Event::poll()) {
            switch (Event::getEventType()) {
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }

        if (textureChronometer.getElapsedTime() >= 5) {
            vim->bind();
        }

        if (textureChronometer.getElapsedTime() >= 10) {
            brick->bind();
            textureChronometer.startChronometer();
        }

        context.clear();
        context.draw();
        context.update();

        // Handle FPS
        fps++;
        if (fpsChronometer.getElapsedTime() >= 1) {
            // context.showFPS(fps);
            fps = 0;
            fpsChronometer.startChronometer();
        }
    }
}
