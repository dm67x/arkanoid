#include "Window.h"

Window::Window() : Window("Arkanoid", 600, 800) {
}

Window::Window(const std::string title, const int width, const int height) {
    _window = SDL_CreateWindow(title.c_str(), 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        width, height, SDL_WINDOW_SHOWN);
    _surface = SDL_GetWindowSurface(_window);
}

Window::~Window() {
    SDL_DestroyWindow(_window);
}

void Window::resize(const int width, const int height) {

}

void Window::update() {
    SDL_UpdateWindowSurface(_window);
}

SDL_Surface * Window::getSurface() {
    return _surface;
}
