#include "render_system.h"
#include "Entity/entity.h"
#include "Component/transform.h"
#include "Component/sprite.h"
#include <iostream>

using namespace Components;

RenderSystem::RenderSystem(SDL_Surface & sprite) 
	: sprite(sprite) {
}

void RenderSystem::draw(SDL_Surface & surface) {
	System::draw(surface);
	
	EntityManager * entity_manager = current->getManager();

	for (auto entity : entity_manager->get()) {
		Transform * tc = entity->get<Transform>("transform");
		Sprite * sc = entity->get<Sprite>("sprite");

		if (!tc || !sc) continue;

		SDL_Rect destination;
		destination.x = static_cast<int>(tc->position.x) - sc->src.w / 2;
		destination.y = static_cast<int>(tc->position.y) - sc->src.h / 2;
		destination.w = static_cast<int>(tc->scale.x * sc->src.w);
		destination.h = static_cast<int>(tc->scale.y * sc->src.h);

		SDL_BlitScaled(&sprite, &sc->src, &surface, &destination);
	}
}
