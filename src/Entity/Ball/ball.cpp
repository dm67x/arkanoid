#include "ball.h"
#include "Component/transform.h"
#include "Component/sprite.h"
#include "Component/control.h"
#include "Component/collision.h"
#include "Component/motion.h"

using namespace Entities;

Ball::Ball(EntityManager * manager) : Entity(manager) {
    Components::Transform * transform = new Components::Transform();
    Components::Sprite * sprite = new Components::Sprite();
    Components::Motion * motion = new Components::Motion();

    transform->position = Vector2<float>(0, 0);
    transform->scale = Vector2<float>(1, 1);
    sprite->src = { 80, 64, 16, 16 };
    motion->velocity = Vector2<float>(0, 0);

    add(transform);
    add(sprite);
    add(motion);
    add(new Components::Control());
    add(new Components::Collision());
}