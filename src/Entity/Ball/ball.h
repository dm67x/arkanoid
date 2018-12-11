#ifndef ENTITY_BALL_H
#define ENTITY_BALL_H

#include "Entity/entity.h"
#include "Component/render_component.h"
#include "Component/collision_component.h"
#include "Component/movement_component.h"

class Ball : public Entity
{
public:
	Ball(uint32_t id, EntityPool * pool);

	RenderComponent * render;
	CollisionComponent * collision;
	MovementComponent * movement;
};

#endif