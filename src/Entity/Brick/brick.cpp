#include "brick.h"

Brick::Brick(Entity id, EntityPool * pool, int points) 
	: id(id), pool(pool) 
{
	// Components
	transform = new TransformComponent(id);
	render = new RenderComponent(id, getGraphicsFromPoints(points));
	collision = new CollisionComponent(id, transform, render);
	this->points = new PointsComponent(id, points);
	hit = new HitComponent(id);

	pool->add(id, *transform);
	pool->add(id, *render);
	pool->add(id, *collision);
	pool->add(id, *this->points);
	pool->add(id, *hit);
}

Brick::~Brick() {
	pool->remove(id, *transform);
	pool->remove(id, *render);
	pool->remove(id, *collision);
	pool->remove(id, *this->points);
	pool->remove(id, *hit);
}

SDL_Rect Brick::getGraphicsFromPoints(int points) {
	switch (points) {
	case 50:
		return { 0, 0, 30, 14 };
	case 60:
		return { 32, 0, 30, 14 };
	case 70:
		return { 64, 0, 30, 14 };
	case 80:
		return { 96, 0, 30, 14 };
	case 90:
		return { 128, 0, 30, 14 };
	case 100:
		return { 160, 0, 30, 14 };
	case 110:
		return { 0, 16, 30, 14 };
	case 120:
		return { 32, 16, 30, 14 };
	default:
		return { 0, 32, 30, 14 };
	}
}