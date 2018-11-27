#include "collider_system.h"

void ColliderSystem::input(SDL_Event e) {

}

void ColliderSystem::update(float deltaTime) {
    for (auto entity : pool->all("ball")) {
        for (auto entity2 : pool->all()) {
            if (entity == entity2) continue;
            if (entity->collideWith(*entity2)) {
                entity->setDirection(entity->getDirection() * Vector2<int>(0, -1));
            }
        }
    }
}

void ColliderSystem::draw(SDL_Surface & surface) {

}