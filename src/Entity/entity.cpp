/**
  * @file entity.cpp
  * @version 1
  */

#include "entity.h"

Entity::Entity(std::string name) : name(name) {
    components.clear();
}

Entity::~Entity() {
}

std::string Entity::getName() {
    return name;
}

std::map<std::string, Component *> Entity::getComponents() {
    return components;
}

void Entity::addComponent(Component * c) {
    if (components.find(name) != components.end()) return;
    components.insert(std::make_pair(c->getName(), c));
}

void Entity::removeComponent(std::string name) {
    if (components.find(name) == components.end()) return;
    components.erase(name);
}

Component * Entity::findComponent(std::string name) {
    if (components.find(name) == components.end()) return nullptr;
    return components.at(name);
}

/*bool Entity::collideWith(Entity & e) {
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
}*/
