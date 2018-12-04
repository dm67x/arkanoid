#ifndef FONT_SYSTEM_H
#define FONT_SYSTEM_H

#include "System/system.h"

class FontSystem : public System
{
private:
	SDL_Surface & sprite;

public:
	FontSystem(SDL_Surface & sprite);
	void draw(SDL_Surface & surface) override;
};

#endif