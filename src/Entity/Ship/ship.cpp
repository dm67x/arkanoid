#include "ship.h"
#include "Component/transform.h"
#include "Component/sprite.h"
#include "Component/control.h"
#include "Component/collision.h"

using namespace Entities;

Ship::Ship() : Entity() {
	Components::Sprite * sc = new Components::Sprite();
	sc->src = { 385, 192, 98, 16 };

	add(new Components::Transform());
	add(sc);
	add(new Components::Control());
	add(new Components::Collision());
}