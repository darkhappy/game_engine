/// @file Application.cpp
/// @brief Contains the implementation of the Application class in Application.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Application.h"

#define ASSETS "../assets"

Application::Application() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
}

Application::~Application() = default;

void Application::start() {
    bool running = true;

    Texture louis(ASSETS"/images/brick.png");
    Texture vim(ASSETS"/images/vim.png");
    Texture gopher(ASSETS"/images/gopher.png");
    TTFont screenFont(ASSETS"/fonts/meslo.ttf", 20, "vim my beloved", {150, 255, 150, 255});
    TTFont gopherFont(ASSETS"/fonts/meslo.ttf", 20, "gopher", {150, 150, 255, 255});
    TTFont louisFont(ASSETS"/fonts/comic.ttf", 96, "DID I ASK", {255, 150, 150, 255});
    TTFont instructionsFont(ASSETS"/fonts/meslo.ttf", 20, "Left click: gopher", {255, 255, 255, 255});
    TTFont instructionsFont2(ASSETS"/fonts/meslo.ttf", 20, "Right click: clear gopher", {255, 255, 255, 255});
    TTFont gopherCountFont(ASSETS"/fonts/meslo.ttf", 20, "Gopher count: 0", {255, 255, 255, 255});

    Screensaver screensaver(&context, &louis, &louisFont, rand() % 200, rand() % 200, 400, 400, 0.5, 0.5);

    std::vector<Screensaver> vimsavers;
    for (int i = 0; i < 10; i++) {
        double height = rand() % 100 + 100;
        vimsavers.emplace_back(&context, &vim, &screenFont, rand() % 800, rand() % 600, height, height,
                               (rand() % 100) / 50.0, (rand() % 100) / 50.0);
    }

    std::vector<Screensaver> gophersavers;

    int frames = 0;
    TTFont framesCounter(ASSETS"/fonts/meslo.ttf", 24, "fps: 0");

    Chronometer tick;
    tick.startChronometer();
    fpsChronometer.startChronometer();

    while (running) {
        while (Event::poll()) {
            switch (Event::getEventType()) {
                case SDL_QUIT:
                    running = false;
                    break;
                    // When the user clicks on the window
                case SDL_MOUSEBUTTONDOWN:
                    // If the user clicks on the left button, create a screensaver at the
                    // position of the mouse
                    if (Event::getMouseButton() == SDL_BUTTON_LEFT) {
                        gophersavers.emplace_back(&context, &gopher, &gopherFont, Event::getMouseX(),
                                                  Event::getMouseY(), 100, 100, rand() % 100 / 25.0,
                                                  rand() % 100 / 25.0);
                        gopherCountFont.setText("Gopher count: " + std::to_string(gophersavers.size()));
                    }

                    // If the user clicks on the right button, clear the vimsavers
                    if (Event::getMouseButton() == SDL_BUTTON_RIGHT) {
                        gophersavers.clear();
                        gopherCountFont.setText("Gopher count: 0");
                    }
                    break;
                default:
                    break;
            }
        }

        // Updating
        // Each tick is 1/120th of a second
        double delta = tick.getElapsedTime();

        if (delta >= 1.0 / 120.0) {
            for (auto &gophersaver: gophersavers) {
                gophersaver.update();
            }

            for (auto &vimsaver: vimsavers) {
                vimsaver.update();
            }

            screensaver.update();
            tick.startChronometer();
        }

        // Drawing
        context.clear();

        context.draw();
        for (auto &screen: gophersavers)
            screen.draw();
        for (auto &screen: vimsavers)
            screen.draw();

        screensaver.draw();
        framesCounter.draw(10, 10);
        instructionsFont.draw(10, 50);
        instructionsFont2.draw(10, 70);
        gopherCountFont.draw(10, 90);
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
