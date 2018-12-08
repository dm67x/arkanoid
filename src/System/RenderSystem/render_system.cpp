#include "render_system.h"
#include "Component/transform_component.h"
#include "Component/render_component.h"

RenderSystem::RenderSystem(SDL_Surface & sprite) 
	: sprite(sprite) {
}

void RenderSystem::draw(SDL_Surface & surface) {
	if (!current_scene) return;

	EntityPool * pool = current_scene->getPool();
	TransformComponent * tc = nullptr;
	RenderComponent * rc = nullptr;

	for (auto entity : pool->getEntities()) {
		for (auto comp : entity.second) {
			if (comp->getName() == "transform") {
				tc = static_cast<TransformComponent *>(comp);
			}
			else if (comp->getName() == "render") {
				rc = static_cast<RenderComponent *>(comp);
			}
		}

		if (tc && rc) {
			SDL_Rect destination;
			destination.x = tc->position.x - rc->src.w / 2;
			destination.y = tc->position.y - rc->src.h / 2;
			destination.w = tc->scale.x * rc->src.w;
			destination.h = tc->scale.y * rc->src.h;

			SDL_BlitSurface(
				&sprite,
				&rc->src,
				&surface,
				&destination);
		}

		tc = nullptr; // remise a zero pour la suite
		rc = nullptr; // remise a zero pour la suite
	}
}
