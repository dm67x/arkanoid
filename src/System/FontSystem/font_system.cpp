#include "font_system.h"
#include "Component/text_component.h"
#include "Component/transform_component.h"

FontSystem::FontSystem(SDL_Surface & sprite) : sprite(sprite) {
}

void FontSystem::draw(SDL_Surface & surface) {
	if (!current_scene) return;

	EntityPool * pool = current_scene->getPool();
	TextComponent * tc = nullptr;
	TransformComponent * trc = nullptr;
	std::vector<SDL_Rect> rects;
	SDL_Rect graphic, dest;

	for (auto entity : pool->getEntities()) {
		for (auto comp : entity.second) {
			if (comp->getName() == "text") {
				tc = static_cast<TextComponent *>(comp);
			}
			else if (comp->getName() == "transform") {
				trc = static_cast<TransformComponent *>(comp);
			}
		}

		if (tc && trc) {
			rects = tc->getRects();
			for (size_t i = 0; i < rects.size(); i++) {
				graphic = rects.at(i);
				dest = {
					static_cast<int>((graphic.w / 2) * i + trc->position.x / 2),
					static_cast<int>(trc->position.y / 2),
					static_cast<int>(graphic.w * trc->scale.x), 
					static_cast<int>(graphic.h * trc->scale.y)
				};
				SDL_BlitScaled(&sprite, &graphic, &surface, &dest);
			}
		}

		tc = nullptr;
		trc = nullptr;
		rects.clear();
	}
}