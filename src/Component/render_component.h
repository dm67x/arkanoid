#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <SDL2/SDL.h>

#include "component.h"

class RenderComponent : public Component
{
public:
	RenderComponent(SDL_Rect src) : Component(), src(src) {}
	
	SDL_Rect src;

	std::string getName() override { return "render"; }
};

#endif