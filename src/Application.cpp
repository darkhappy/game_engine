/// @file Application.cpp
/// @brief Contains the implementation of the Application class in Application.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Application.h"

Application::Application() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

Application::~Application() = default;

void Application::start() {
    bool running = true;
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

        context.clear();
        context.update();
    }
}

Application &Application::GetInstance() {
    return instance;
}

Application Application::instance;