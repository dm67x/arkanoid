/**
  * @file entity.cpp
  * @version 1
  */

#include "entity.h"

Entity::Entity(std::string name)
    : _name(name), _position(Vector2<int>(0, 0)) {
}

Entity::Entity(std::string name, Vector2<int> position)
    : _name(name), _position(position) {
}

Entity::~Entity() {
}

void Entity::setPosition(Vector2<int> position) {
    this->_position = position;
}

Vector2<int> Entity::getPosition() {
    return _position;
}

std::string Entity::getName() {
    return _name;
}

SDL_Rect Entity::getRect() {
    return _src_rect;
}

bool Entity::collideWith(Entity & e) {
    SDL_Rect bounding_e, bounding;
    Vector2<int> position_e = e.getPosition();
    Vector2<int> position = getPosition();
    SDL_Rect e_src_rect = e.getRect();

    bounding_e.x = position_e._x - e_src_rect.w / 2;
    bounding_e.y = position_e._y - e_src_rect.h / 2;
    bounding_e.w = position_e._x + e_src_rect.w / 2;
    bounding_e.h = position_e._y + e_src_rect.h / 2;

    bounding.x = position._x - _src_rect.w / 2;
    bounding.y = position._y - _src_rect.h / 2;
    bounding.w = position._x + _src_rect.w / 2;
    bounding.h = position._y + _src_rect.h / 2;

    return (bounding_e.w > bounding.x
            && bounding_e.h > bounding.y
            && bounding_e.x < bounding.w
            && bounding_e.y < bounding.h);
}
