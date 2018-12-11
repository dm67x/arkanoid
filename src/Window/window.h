#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "vector2.h"
#include "singleton.h"

class Window : public Singleton<Window>
{

private:
    SDL_Window * window;
    SDL_Surface * surface;

	int width, height;
	std::string title;

public:
	Window();
    ~Window();

	void setTitle(const std::string title);
    void resize(const int width, const int height);
    void update();

    SDL_Surface * getSurface();
	Vector2<int> getSize() const;

};

#endif // WINDOW_H
