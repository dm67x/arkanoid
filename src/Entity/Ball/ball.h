#ifndef ENTITY_BALL_H
#define ENTITY_BALL_H

#include "Entity/entity.h"
#include "Entity/entity_pool.h"
#include "Component/transform_component.h"
#include "Component/render_component.h"
#include "Component/collision_component.h"
#include "Component/movement_component.h"
#include "Component/type_component.h"

class Ball
{
private:
	EntityPool * pool;
	Entity id;

public:
	Ball(Entity id, EntityPool * pool);
	~Ball();

	TransformComponent * transform;
	RenderComponent * render;
	CollisionComponent * collision;
	MovementComponent * movement;
	TypeComponent * type;
};

#endif