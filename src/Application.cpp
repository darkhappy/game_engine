//
// Created by Jean-Philippe on 2022-09-07.
//

#include "Application.h"

void Application::AddWindow(Window *window) {
    windows.push_back(window);
}

void Application::RemoveWindow(Window *window) {
    windows.erase(std::remove(windows.begin(), windows.end(), window), windows.end());
    delete window;
}

Application::Application() {
    SDL_Init(SDL_INIT_EVERYTHING);
    std::vector<Window *>();
}

Application::~Application() {
    for (Window *window: windows) {
        delete window;
    }
    windows.clear();
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
                case SDL_WINDOWEVENT:
                    if (Event::GetWindowEvent() == SDL_WINDOWEVENT_CLOSE) {
                        for (Window *window: windows) {
                            if (window->GetWindowId() == Event::GetWindowId()) {
                                RemoveWindow(window);
                                break;
                            }
                        }
                    }
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
