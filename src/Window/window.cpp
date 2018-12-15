#include "window.h"

Window::Window() {
	title = "Arkanoid";
	width = 362;
	height = 500;
	window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

void Window::setTitle(const std::string title) {
	this->title = title;
	SDL_SetWindowTitle(window, title.c_str());
}

void Window::resize(const int width, const int height) {
	this->width = width;
	this->height = height;
	SDL_SetWindowSize(window, width, height);
}

void Window::update() {
    SDL_UpdateWindowSurface(window);
}

SDL_Surface * Window::getSurface() {
    return surface;
}

Vector2<int> Window::getSize() const {
	return Vector2<int>(width, height);
}
