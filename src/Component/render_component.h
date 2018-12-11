#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <SDL2/SDL.h>

#include "component.h"

class RenderComponent : public Component
{
public:
	RenderComponent(Entity entity, SDL_Rect src) : Component(entity), src(src) {}
	
	SDL_Rect src;

	std::string getName() override { return "render"; }
};

#endif