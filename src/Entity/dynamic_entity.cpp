#include "dynamic_entity.h"

void DynamicEntity::move() {
    Vector2<int> position = getPosition();
    position.x += static_cast<int>(direction.x * speed);
    position.y += static_cast<int>(direction.y * speed);
    setPosition(position);
}

void DynamicEntity::setDirection(Vector2<float> direction) {
    this->direction = direction;
}