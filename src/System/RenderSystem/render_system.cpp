#include "render_system.h"

RenderSystem::RenderSystem(SDL_Surface * sprite) {
    this->sprite = sprite;
}

void RenderSystem::draw(SDL_Surface & surface) {
	if (!pool) return;

	SDL_Rect graphic, bounding;
    for (auto entity : pool->all()) {
		graphic = entity->getGraphic();
		bounding = entity->getBoundingBox();
        SDL_BlitSurface(
            sprite, 
            &graphic, 
            &surface, 
            &bounding);
    }
}
