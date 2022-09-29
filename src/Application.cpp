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

    std::srand(std::time(nullptr)); // use current time as seed for random generator

    Texture gopher(ASSETS"/images/gopher.png");
    TTFont gopherFont(ASSETS"/fonts/meslo.ttf", 20, "gopher gopher gopher gopher", {150, 150, 255, 255});
    TTFont instructionsFont(ASSETS"/fonts/meslo.ttf", 20, "Left click: gopher", {255, 255, 255, 255});
    TTFont instructionsFont2(ASSETS"/fonts/meslo.ttf", 20, "Right click: clear gopher", {255, 255, 255, 255});
    TTFont gopherCountFont(ASSETS"/fonts/meslo.ttf", 20, "Gopher count: 0", {255, 255, 255, 255});

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

                        int forward = rand() % 100000 > 50000 ? 1 : -1;
                        int up = rand() % 100000 > 50000 ? 1 : -1;

                        gophersavers.emplace_back(&context, &gopher, &gopherFont, Event::getMouseX(),
                                                  Event::getMouseY(), 100, 100, rand() % 100 / 25.0 * forward,
                                                  rand() % 100 / 25.0 * up);
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
            for (auto &gophersaver: gophersavers)
                gophersaver.update();

            tick.startChronometer();
        }

        // Drawing
        context.clear();

        context.draw();
        for (auto &screen: gophersavers)
            screen.draw();

        GLContext::drawFont(framesCounter, Vector3d(10, 10));
        GLContext::drawFont(instructionsFont, Vector3d(10, 80));
        GLContext::drawFont(instructionsFont2, Vector3d(10, 105));
        GLContext::drawFont(gopherCountFont, Vector3d(10, 35));

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
