#include "ship.h"

Ship::Ship(Entity id, EntityPool * pool) 
	: id(id), pool(pool) 
{
	// Components
	transform = new TransformComponent(id);
	render = new RenderComponent(id, { 385, 192, 98, 16 });
	movement = new MovementComponent(id);
	collision = new CollisionComponent(id, transform, render);
	movement->is_static = true;
	type = new TypeComponent(id, "ship");

	pool->add(id, *transform);
	pool->add(id, *render);
	pool->add(id, *movement);
	pool->add(id, *collision);
	pool->add(id, *type);
}

Ship::~Ship() {
	pool->remove(id);
}