#ifndef ENTITY_SHIP_H
#define ENTITY_SHIP_H

#include "Entity/entity.h"
#include "Entity/entity_pool.h"
#include "Component/transform_component.h"
#include "Component/render_component.h"
#include "Component/collision_component.h"
#include "Component/movement_component.h"

class Ship
{
private:
	EntityPool * pool;
	Entity id;

public:
	Ship(Entity id, EntityPool * pool);
	~Ship();

	TransformComponent * transform;
	RenderComponent * render;
	CollisionComponent * collision;
	MovementComponent * movement;
};

#endif