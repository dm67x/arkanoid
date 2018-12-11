#ifndef ENTITY_SHIP_H
#define ENTITY_SHIP_H

#include "Entity/entity.h"
#include "Component/render_component.h"
#include "Component/collision_component.h"
#include "Component/movement_component.h"

class Ship : public Entity
{
public:
	Ship(uint32_t id, EntityPool * pool);

	RenderComponent * render;
	CollisionComponent * collision;
	MovementComponent * movement;
};

#endif