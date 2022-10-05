/// @file Application.cpp
/// @brief Contains the implementation of the Application class in Application.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Application.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

#include "Event.h"
#include "Screensaver.h"

#define ASSETS "../assets"

Application::Application() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
}

Application::~Application() = default;

void Application::start() {
    bool running = true;
    int frames = 0;

    std::srand(std::time(nullptr));

    Texture gopher(ASSETS "/images/gopher.png");

    TTFont gopherFont(ASSETS "/fonts/meslo.ttf", 20, "gopher gopher gopher gopher", {150, 150, 255, 255});
    TTFont instructionsFont(ASSETS "/fonts/meslo.ttf", 20, "Left click: gopher", {255, 255, 255, 255});
    TTFont instructionsFont2(ASSETS "/fonts/meslo.ttf", 20, "Right click: clear gopher", {255, 255, 255, 255});
    TTFont gopherCountFont(ASSETS "/fonts/meslo.ttf", 20, "Gopher count: 0", {255, 255, 255, 255});
    TTFont framesCounter(ASSETS "/fonts/meslo.ttf", 24, "fps: 0");

    auto *gopherText = new Texture(*gopherFont.getSurface(), true);
    auto *instructions = new Texture(*instructionsFont.getSurface(), true);
    auto *instructions2 = new Texture(*instructionsFont2.getSurface(), true);
    auto *gopherCount = new Texture(*gopherCountFont.getSurface(), true);
    auto *framesCounterText = new Texture(*framesCounter.getSurface(), true);

    Chronometer tick;
    std::vector<Screensaver> gophersavers;

    tick.reset();
    fpsChronometer.reset();

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

                        int amount = rand() % 500 + 50;
                        for (int i = 0; i < amount; i++) {
                            int forward = rand() % 100000 > 50000 ? 1 : -1;
                            int up = rand() % 100000 > 50000 ? 1 : -1;

                            gophersavers.emplace_back(&context, &gopher, gopherText, Event::getMouseX(),
                                                      Event::getMouseY(), 100, 100, rand() % 100 / 25.0 * forward,
                                                      rand() % 100 / 25.0 * up);
                        }
                        delete gopherCount;
                        gopherCount = new Texture(*gopherCountFont.setText("Gopher count: " + std::to_string(gophersavers.size())));
                    }

                    // If the user clicks on the right button, clear the vimsavers
                    if (Event::getMouseButton() == SDL_BUTTON_RIGHT) {
                        gophersavers.clear();
                        delete gopherCount;
                        gopherCount = new Texture(*gopherCountFont.setText("Gopher count: 0"));
                    }
                    break;
                default:
                    break;
            }
        }

        // Updating
        // Each tick is 1/120th of a second
        double delta = tick.getDelta();

        if (delta >= 1.0 / 120.0) {
            for (auto &gophersaver: gophersavers)
                gophersaver.update();

            tick.reset();
        }

        // Drawing
        context.clear();

        context.draw();
        for (auto &screen: gophersavers)
            screen.draw();

        framesCounterText->bind();
        GLContext::drawRectangle(Vector3d(10, 10), Vector3d(framesCounterText->getWidth(), framesCounterText->getHeight()));

        gopherCount->bind();
        GLContext::drawRectangle(Vector3d(10, 40), Vector3d(gopherCount->getWidth(), gopherCount->getHeight()));

        instructions->bind();
        GLContext::drawRectangle(Vector3d(10, 80), Vector3d(instructions->getWidth(), instructions->getHeight()));

        instructions2->bind();
        GLContext::drawRectangle(Vector3d(10, 105), Vector3d(instructions2->getWidth(), instructions2->getHeight()));

        context.update();

        // Handle FPS
        frames++;
        if (fpsChronometer.getDelta() >= 1) {
            fps = frames / fpsChronometer.getDelta();
            frames = 0;
            delete framesCounterText;
            framesCounter.setText("fps: " + std::to_string(fps));
            framesCounterText = new Texture(*framesCounter.getSurface());
            fpsChronometer.reset();
        }
    }
}
