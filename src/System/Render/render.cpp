#include "render.h"

using namespace Systems;

Render::Render() {
	_sprite = SDL_LoadBMP("./Arkanoid_sprites.bmp");
	SDL_SetColorKey(_sprite, true, 0);
}

Render::~Render() {
}

void Render::update(double dt) {

}

void Render::draw(SDL_Surface & surface) {
	SDL_Rect dst_rect, e_rect;

	for (auto e : _entity_factory->getEntities()) {
		e_rect = e->getRect();

		dst_rect.x = e->getPosition()._x - e_rect.w / 2;
		dst_rect.y = e->getPosition()._y - e_rect.h / 2;
		dst_rect.w = e_rect.w;
		dst_rect.h = e_rect.h;
		SDL_BlitSurface(_sprite, &e_rect, &surface, &dst_rect);
	}
}