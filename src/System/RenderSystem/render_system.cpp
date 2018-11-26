#include "render_system.h"

RenderSystem::RenderSystem(SDL_Surface * sprite) {
    this->sprite = sprite;
}

void RenderSystem::input(SDL_Event e) {
    
}

void RenderSystem::update(float deltaTime) {
    // Do nothing
}

void RenderSystem::draw(SDL_Surface & surface) {
    for (auto entity : pool->all()) {
        SDL_BlitSurface(
            sprite, 
            &entity->getGraphic(), 
            &surface, 
            &entity->getBoundingBox());
    }
}