/// @file Application.cpp
/// @brief Contains the implementation of the Application class in Application.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Application.h"
#include "Screensaver.h"

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

    Texture louis("../assets/images/brick.png");
    Texture vim("../assets/images/vim.png");

    Screensaver screensaver(&context, &louis, rand() % 200, rand() % 200, 400, 400, 0.5, 0.5);

    std::vector<Screensaver> screensavers;
    for (int i = 0; i < 1; i++) {
        double height = rand() % 100 + 100;
        screensavers.emplace_back(&context, &vim, rand() % 800, rand() % 600, height, height,
                                  (rand() % 100) / 10.0, (rand() % 100) / 10.0);
    }

    int frames = 0;

    Chronometer tick;
    tick.startChronometer();

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

        // Updating
        // Each tick is 1/120th of a second
        double delta = tick.getElapsedTime();

        if (delta >= 1.0 / 120.0) {
            for (auto &screen : screensavers) {
                screen.update();
            }
            screensaver.update();
            tick.startChronometer();
        }

        // Drawing
        context.clear();
        context.draw();
        for (auto &screen: screensavers)
            screen.draw();
        screensaver.draw();
        context.showFPS(fps);
        context.update();

        // Handle FPS
        frames++;
        if (fpsChronometer.getElapsedTime() >= 1) {
            fps = frames / fpsChronometer.getElapsedTime();
            frames = 0;
            fpsChronometer.startChronometer();
        }
    }
}
