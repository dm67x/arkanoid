#include "ball.h"

Ball::Ball(Entity id, EntityPool * pool)
	: id(id), pool(pool) 
{
	// Components
	transform = new TransformComponent(id);
	render = new RenderComponent(id, { 80, 64, 16, 16 });
	movement = new MovementComponent(id, 5.0f, Vector2<float>(0, -1), true);
	collision = new CollisionComponent(id, transform, render);
	collision->q = 2;
	type = new TypeComponent(id, "ball");

	pool->add(id, *transform);
	pool->add(id, *render);
	pool->add(id, *movement);
	pool->add(id, *collision);
	pool->add(id, *type);
}

Ball::~Ball() {
	pool->remove(id);
}