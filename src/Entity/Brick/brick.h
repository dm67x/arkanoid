#ifndef ENTITY_BRICK_H
#define ENTITY_BRICK_H

#include "Entity/entity.h"
#include "Component/render_component.h"
#include "Component/collision_component.h"
#include "Component/hit_component.h"
#include "Component/points_component.h"

class Brick : public Entity
{
private:
	SDL_Rect getGraphicsFromPoints(int points);

public:
	Brick(uint32_t id, EntityPool * pool, int points);

	RenderComponent * render;
	CollisionComponent * collision;
	HitComponent * hit;
	PointsComponent * points;
};

#endif