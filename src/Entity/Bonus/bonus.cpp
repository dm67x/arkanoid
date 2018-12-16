#include "bonus.h"
#include "Component/bonus.h"
#include "Component/motion.h"
#include "Component/transform.h"
#include "Component/sprite.h"

using namespace Entities;

Bonus::Bonus() : Entity() {
    add(new Components::Bonus());
    add(new Components::Motion());
    add(new Components::Transform());
    add(new Components::Sprite());
}