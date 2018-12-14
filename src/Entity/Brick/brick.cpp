#include "brick.h"
#include "Component/transform.h"
#include "Component/sprite.h"
#include "Component/health.h"
#include "Component/collision.h"
#include "Component/points.h"
#include "Component/bonus.h"

using namespace Entities;

Brick::Brick(EntityManager * manager) : Entity(manager) {
    Components::Sprite * sprite = new Components::Sprite();
    sprite->src = { 0, 0, 30, 14 };

    add(new Components::Transform());
    add(sprite);
    add(new Components::Health());
    add(new Components::Points());
    add(new Components::Collision());
    add(new Components::Bonus());
}