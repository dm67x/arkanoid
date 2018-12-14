#include "ship.h"
#include "Component/transform.h"
#include "Component/sprite.h"
#include "Component/control.h"
#include "Component/collision.h"

using namespace Entities;

Ship::Ship(EntityManager * manager) : Entity(manager) {
	Components::Transform * tc = new Components::Transform();
	tc->position = Vector2<float>(0, 0);
	tc->scale = Vector2<float>(1.0f, 1.0f);

	Components::Sprite * sc = new Components::Sprite();
	sc->src = { 385, 192, 98, 16 };

	add(tc);
	add(sc);
	add(new Components::Control());
	add(new Components::Collision());
}