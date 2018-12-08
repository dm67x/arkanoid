#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include "component.h"
#include "vector2.h"

class MovementComponent : public Component
{
public:
	MovementComponent(Entity entity, float s, Vector2<float> d, bool is_static) 
		: Component(entity), speed(s), direction(d), is_static(is_static) {}

	MovementComponent(Entity entity, float s, Vector2<float> d) 
		: MovementComponent(entity, s, d, false) {}

	MovementComponent(Entity entity) 
		: MovementComponent(entity, 1.0f, Vector2<float>(0, 0)) {}

	bool is_static;
	float speed;
	Vector2<float> direction;

	std::string getName() override { return "movement"; }
};

#endif