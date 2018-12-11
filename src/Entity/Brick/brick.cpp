#include "brick.h"

Brick::Brick(uint32_t id, EntityPool * pool, int points) 
	: Entity(id, pool, "brick")
{
	// Components
	render = new RenderComponent(getGraphicsFromPoints(points));
	collision = new CollisionComponent(transform, render);
	this->points = new PointsComponent(points);
	hit = new HitComponent();

	pool->add(id, *render);
	pool->add(id, *collision);
	pool->add(id, *this->points);
	pool->add(id, *hit);
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