#include "render_system.h"
#include "Entity/entity.h"
#include "Component/transform.h"
#include "Component/sprite.h"
#include <iostream>

RenderSystem::RenderSystem(SDL_Surface & sprite) 
	: sprite(sprite) {
}

void RenderSystem::draw(SDL_Surface & surface) {
	if (!current_scene) return;

	EntityManager * entity_manager = current_scene->getEntityManager();

	for (auto entity : entity_manager->get()) {
		Components::Transform * tc = static_cast<Components::Transform *>(entity->get("transform"));
		Components::Sprite * sc = static_cast<Components::Sprite *>(entity->get("sprite"));

		if (!tc || !sc) continue;

		SDL_Rect destination;
		destination.x = static_cast<int>(tc->position.x) - sc->src.w / 2;
		destination.y = static_cast<int>(tc->position.y) - sc->src.h / 2;
		destination.w = static_cast<int>(tc->scale.x * sc->src.w);
		destination.h = static_cast<int>(tc->scale.y * sc->src.h);

		SDL_BlitSurface(&sprite, &sc->src, &surface, &destination);
	}
}
