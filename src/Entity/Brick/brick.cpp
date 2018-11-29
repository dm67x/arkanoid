#include "brick.h"
#include "Entity/entity_factory.h"

using namespace Entities;

Brick::Brick() : Brick(1) {
}

Brick::Brick(int hit) : StaticEntity("Brick") {
    this->hit = hit;
    makeDestructible();
    setGraphic({ 0, 0, 31, 15 });
}

Brick::~Brick() {
}

void Brick::setHit(int hit) {
    this->hit = hit;
}

void Brick::damage(int force) {
    if (!destructible) return;
    hit -= force;
    if (hit <= 0) {
        Singleton<EntityFactory>::getInstance()->destroy(this); // destroy animation WIP
    }
}

void Brick::makeDestructible() {
    destructible = true;
}

void Brick::makeInvicible() {
    destructible = false;
}

std::string Brick::getType() {
    return "brick";
}