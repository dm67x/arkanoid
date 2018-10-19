#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>
#include <vector>

class Window
{

private:
	SDL_Window * _window;
	SDL_Surface * _surface;

public:
	Window();
	Window(const std::string title, const int width, const int height);
	~Window();

	void resize(const int width, const int height);
	void update();

};

#endif // WINDOW_H
