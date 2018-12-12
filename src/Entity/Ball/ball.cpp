#include "ball.h"

using namespace Entities;

Ball::Ball(EntityManager * manager) : manager(manager) {
    id = manager->createEntity();
    transform = static_cast<Components::Transform *>(manager->addComponent(id, "transform"));
    sprite = static_cast<Components::Sprite *>(manager->addComponent(id, "sprite"));
    manager->addComponent(id, "control");

    transform->position = Vector2<float>(0, 0);
    transform->scale = Vector2<float>(1, 1);
    sprite->src = { 80, 64, 16, 16 };
}

Ball::~Ball() {
    manager->removeEntity(id);
}