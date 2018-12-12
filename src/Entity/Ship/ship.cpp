#include "ship.h"

using namespace Entities;

Ship::Ship(EntityManager * manager) : manager(manager) {
	id = manager->createEntity();
	transform = static_cast<Components::Transform *>(manager->addComponent(id, "transform"));
    sprite = static_cast<Components::Sprite *>(manager->addComponent(id, "sprite"));
    manager->addComponent(id, "control");
	manager->addComponent(id, "collision");

	transform->position = Vector2<float>(0, 0);
	transform->scale = Vector2<float>(1.0f, 1.0f);	
	sprite->src = { 385, 192, 98, 16 };	
}

Ship::~Ship() {
    manager->removeEntity(id);
}