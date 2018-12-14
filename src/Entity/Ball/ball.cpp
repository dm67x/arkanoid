#include "ball.h"
#include "Component/transform.h"
#include "Component/sprite.h"
#include "Component/control.h"
#include "Component/collision.h"
#include "Component/motion.h"

using namespace Entities;

Ball::Ball(EntityManager * manager) : Entity(manager) {
    Components::Sprite * sprite = new Components::Sprite();
    sprite->src = { 80, 64, 16, 16 };

    add(new Components::Transform());
    add(sprite);
    add(new Components::Motion());
    add(new Components::Control());
    add(new Components::Collision());
}