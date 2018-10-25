#include "Ship.h"

Ship::Ship() : Entity() {
    _srcRect = { 128, 0, 128, 32 };
    _destRect = { 0, 0, 128, 32 };
}

void Ship::init() {
    _destRect.x = _window->getSurface()->w / 2;
    _destRect.y = _window->getSurface()->h - 32;
}

void Ship::update() {

}

void Ship::draw() {
    SDL_BlitSurface(_entitiesSurface, &_srcRect, _window->getSurface(), &_destRect);
}
