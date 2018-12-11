#include "ball.h"

Ball::Ball(uint32_t id, EntityPool * pool)
	: Entity(id, pool, "ball") 
{
	// Components
	render = new RenderComponent({ 80, 64, 16, 16 });
	movement = new MovementComponent(5.0f, Vector2<float>(0, -1), true);
	collision = new CollisionComponent(transform, render);
	collision->q = 2;

	pool->add(id, *render);
	pool->add(id, *movement);
	pool->add(id, *collision);
}