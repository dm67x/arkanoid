#include "window.h"

Window::Window() : Window("Arkanoid", 600, 800) {
}

Window::Window(const std::string title, const int width, const int height) {
    window = SDL_CreateWindow(title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_SHOWN);
    surface = SDL_GetWindowSurface(window);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

void Window::resize(const int width, const int height) {

}

void Window::update() {
    SDL_UpdateWindowSurface(window);
}

SDL_Surface * Window::getSurface() {
    return surface;
}
