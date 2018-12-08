#ifndef ENTITY_BRICK_H
#define ENTITY_BRICK_H

#include "Entity/entity.h"
#include "Entity/entity_pool.h"
#include "Component/transform_component.h"
#include "Component/render_component.h"
#include "Component/collision_component.h"
#include "Component/hit_component.h"
#include "Component/points_component.h"

class Brick
{
private:
	Entity id;
	EntityPool * pool;

	SDL_Rect getGraphicsFromPoints(int points);

public:
	Brick(Entity id, EntityPool * pool, int points);
	~Brick();

	TransformComponent * transform;
	RenderComponent * render;
	CollisionComponent * collision;
	HitComponent * hit;
	PointsComponent * points;
};

#endif