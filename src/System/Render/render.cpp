#include "render.h"
#include "Component/Graphic/graphic.h"
#include "Component/Position/position.h"

using namespace Systems;

Render::Render() {
	sprite = SDL_LoadBMP("./Arkanoid_sprites.bmp");
	SDL_SetColorKey(sprite, true, 0);
}

Render::~Render() {
}

void Render::update(double dt) {

}

void Render::draw(SDL_Surface & surface) {
	SDL_Rect dst_rect, e_rect;
	Components::Graphic * graphic;
	Components::Position * position;

	for (auto e : _entity_factory->getEntities()) {
		graphic = nullptr;
		position = nullptr;

		for (auto c : e->getComponents()) {
			if (c.second->getName() == "graphic") {
				graphic = dynamic_cast<Components::Graphic *>(c.second);
			} else if (c.second->getName() == "position") {
				position = dynamic_cast<Components::Position *>(c.second);
			}
		}

		if (graphic && position) {
			e_rect = graphic->getRect();

			dst_rect.x = position->getPosition()._x - e_rect.w / 2;
			dst_rect.y = position->getPosition()._y - e_rect.h / 2;
			dst_rect.w = e_rect.w;
			dst_rect.h = e_rect.h;
			SDL_BlitSurface(sprite, &e_rect, &surface, &dst_rect);
		}
	}
}