/// @file Application.cpp
/// @brief Contains the implementation of the Application class in Application.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Application.h"

Application::Application() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

Application::~Application() {
    Quit();
}

void Application::AddWindow(Window *window) {
    windows[window->GetWindowID()] = window;
}

void Application::RemoveWindow(unsigned int windowID) {
    delete windows[windowID];
    windows.erase(windowID);
}

void Application::Run() {
    while (!windows.empty()) {
        while (Event::PollEvent()) {
            switch (Event::GetEventType()) {
                case SDL_QUIT:
                    Quit();
                    break;
                case SDL_WINDOWEVENT:
                    switch (Event::GetWindowEventType()) {
                        case SDL_WINDOWEVENT_CLOSE:
                            RemoveWindow(Event::GetWindowID());
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        for (auto window: windows) {
            window.second->Clear();
            window.second->Update();
        }
    }
}

void Application::Quit() {
    for (auto window: windows) {
        delete window.second;
    }
    windows.clear();
    SDL_Quit();
}
