#include "Ball.h"

Ball::Ball() : Entity() {
    _srcRect = { 0, 64, 24, 24 };
    _destRect = { 0, 0, 24, 24 };
}

void Ball::init() {
    _destRect.x = _window->getSurface()->w / 2;
    _destRect.y = _window->getSurface()->h / 2;
}

void Ball::update() {

}

void Ball::draw() {
    SDL_BlitSurface(_entitiesSurface, &_srcRect, _window->getSurface(), &_destRect);
}
