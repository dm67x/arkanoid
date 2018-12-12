#include "brick.h"

using namespace Entities;

Brick::Brick(EntityManager * manager) : manager(manager) {
    id = manager->createEntity();
    manager->addComponent(id, "collision");
    transform = static_cast<Components::Transform *>(manager->addComponent(id, "transform"));
    sprite = static_cast<Components::Sprite *>(manager->addComponent(id, "sprite"));
    health = static_cast<Components::Health *>(manager->addComponent(id, "health"));
    points = static_cast<Components::Points *>(manager->addComponent(id, "points"));

    transform->position = Vector2<float>(0, 0);
    transform->scale = Vector2<float>(1, 1);
    points->points = 50;
    health->life = 1;
    sprite->src = { 0, 0, 30, 14 };
}

Brick::~Brick() {
    manager->removeEntity(id);
}