//
// Created by Jean-Philippe on 2022-09-07.
//

#include "Application.h"

void Application::AddWindow(Window *window) {
    windows.push_back(window);
}

Application::Application() {
    SDL_Init(SDL_INIT_EVERYTHING);
    std::vector<Window *>();
}

Application::~Application() {
    for (Window *window: windows) {
        delete window;
    }
    SDL_Quit();
}

void Application::Run() {
    bool running = true;
    while (running) {
        while (Event::PollEvent()) {
            switch (Event::GetEventType()) {
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }

        for (Window *window: windows) {
            window->Clear();
            window->Update();
        }
    }
}

void Application::Quit() {
}
