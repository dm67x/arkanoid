#include "brick.h"
#include "Component/transform.h"
#include "Component/sprite.h"
#include "Component/health.h"
#include "Component/collision.h"
#include "Component/points.h"

using namespace Entities;

Brick::Brick(EntityManager * manager) : Entity(manager) {
    Components::Transform * transform = new Components::Transform();
    Components::Sprite * sprite = new Components::Sprite();
    Components::Health * health = new Components::Health();
    Components::Points * points = new Components::Points();

    transform->position = Vector2<float>(0, 0);
    transform->scale = Vector2<float>(1, 1);
    points->points = 50;
    health->life = 1;
    sprite->src = { 0, 0, 30, 14 };

    add(transform);
    add(sprite);
    add(health);
    add(points);
    add(new Components::Collision());
}