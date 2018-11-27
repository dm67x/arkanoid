#include "dynamic_entity.h"

void DynamicEntity::move() {
    Vector2<int> position = getPosition();
    position = position + direction * speed;
    setPosition(position);
}

void DynamicEntity::setDirection(Vector2<int> direction) {
    this->direction = direction;
}