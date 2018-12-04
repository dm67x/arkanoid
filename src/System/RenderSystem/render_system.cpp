#include "render_system.h"

RenderSystem::RenderSystem(SDL_Surface & sprite) : sprite(sprite) {
}

void RenderSystem::draw(SDL_Surface & surface) {
	if (!pool) return;

	SDL_Rect graphic, bounding;
    for (auto entity : pool->all()) {
		if (entity->getType() == "text") continue;

		graphic = entity->getGraphic();
		bounding = entity->getBoundingBox();
        SDL_BlitSurface(
            &sprite, 
            &graphic, 
            &surface, 
            &bounding);
    }
}
