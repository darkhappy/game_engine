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
    Quit();
}

void Application::Run() {
    while (!windows.empty()) {
        while (Event::PollEvent()) {
            switch (Event::GetEventType()) {
                case SDL_QUIT:
                    Quit();
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
    for (Window *window: windows) {
        delete window;
    }
    windows.clear();
    SDL_Quit();
}
