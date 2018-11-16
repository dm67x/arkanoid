#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>
#include <vector>
#include "vector2.h"

class Window
{

private:
    SDL_Window * _window;
    SDL_Surface * _surface;

	int _width, _height;

public:
    Window();
    Window(const std::string title, const int width, const int height);
    ~Window();

    void resize(const int width, const int height);
    void update();

    SDL_Surface * getSurface();
	Vector2<int> getSize() const;

};

#endif // WINDOW_H
