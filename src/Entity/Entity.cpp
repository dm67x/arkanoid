#include "Entity.h"

SDL_Surface * Entity::_entitiesSurface = SDL_LoadBMP("./sprites.bmp");

Entity::Entity() {
}

Entity::~Entity() {

}

void Entity::add(Window * window) {
    _window = window;
}
