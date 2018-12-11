#include "ship.h"

Ship::Ship(uint32_t id, EntityPool * pool) 
	: Entity(id, pool, "ship")
{
	// Components
	render = new RenderComponent({ 385, 192, 98, 16 });
	movement = new MovementComponent();
	collision = new CollisionComponent(transform, render);
	movement->is_static = true;

	pool->add(id, *render);
	pool->add(id, *movement);
	pool->add(id, *collision);
}