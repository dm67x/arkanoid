#include "render_system.h"
#include <iostream>

RenderSystem::RenderSystem(SDL_Surface & sprite) 
	: sprite(sprite) {
}

void RenderSystem::draw(SDL_Surface & surface) {
	if (!current_scene) return;

	EntityManager * entity_manager = current_scene->getEntityManager();

	for (auto entity : entity_manager->getEntities()) {
		try {
			Components::Transform * tc = component_manager->getTransforms().at(entity);
			Components::Sprite * sc = component_manager->getSprites().at(entity);

			SDL_Rect destination;
			destination.x = static_cast<int>(tc->position.x) - sc->src.w / 2;
			destination.y = static_cast<int>(tc->position.y) - sc->src.h / 2;
			destination.w = static_cast<int>(tc->scale.x * sc->src.w);
			destination.h = static_cast<int>(tc->scale.y * sc->src.h);

			SDL_BlitSurface(&sprite, &sc->src, &surface, &destination);
		} catch (std::out_of_range ex) {
			std::cerr << ex.what() << std::endl;
			continue; // Entite ne correspond pas
		}
	}
}
