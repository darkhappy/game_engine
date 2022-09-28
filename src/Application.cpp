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

    Texture louis("../assets/images/brick.png");
    Texture vim("../assets/images/vim.png");
    TTFont screenFont("../assets/fonts/comic.ttf", 24, "vim is BASED af");

    Screensaver screensaver(&context, &louis, nullptr, rand() % 200, rand() % 200, 400, 400, 0.5, 0.5);

    std::vector<Screensaver> screensavers;
    for (int i = 0; i < 10; i++) {
        double height = rand() % 100 + 100;
        screensavers.emplace_back(&context, &vim, &screenFont, rand() % 800, rand() % 600, height, height,
                                    (rand() % 100) / 50.0, (rand() % 100) / 50.0);
    }

    int frames = 0;
    TTFont framesCounter("../assets/fonts/comic.ttf", 24, "fps: 0");

    Chronometer tick;
    tick.startChronometer();
    fpsChronometer.startChronometer();

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

        int i = 0;
        while (i * framesCounter.getHeight() < context.getHeight()) {
            framesCounter.draw(0, framesCounter.getHeight() * i);
            i++;
        }
        context.update();

        // Handle FPS
        frames++;
        if (fpsChronometer.getElapsedTime() >= 1) {
            fps = frames / fpsChronometer.getElapsedTime();
            frames = 0;
            framesCounter.setText("fps: " + std::to_string(fps));
            fpsChronometer.startChronometer();
        }
    }
}
