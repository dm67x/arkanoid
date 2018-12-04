#include "font_system.h"
#include "Entity/Text/text.h"

FontSystem::FontSystem(SDL_Surface & sprite) : sprite(sprite) {
}

void FontSystem::draw(SDL_Surface & surface) {
	if (!pool) return;

	std::vector<SDL_Rect> graphics;
	Vector2<float> position;
	Entities::Text * text = nullptr;
	SDL_Rect dest, graphic;

	for (auto entity : pool->all("text")) {
		text = dynamic_cast<Entities::Text *>(entity);
		if (text) {
			position = text->getPosition();
			graphics = text->getTextGraphics();
			for (int i = 0; i < graphics.size(); i++) {
				graphic = graphics.at(i);
				dest = { 
					graphic.w * i + static_cast<int>(position.x), 
					static_cast<int>(position.y), 
					graphic.w, graphic.h 
				};
				SDL_BlitSurface(&sprite, &graphic, &surface, &dest);
			}
		}
	}
}