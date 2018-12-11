#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include "component.h"
#include "vector2.h"

class MovementComponent : public Component
{
public:
	MovementComponent(float s, Vector2<float> d, bool is_static) 
		: Component(), speed(s), direction(d), is_static(is_static) {}

	MovementComponent(float s, Vector2<float> d) 
		: MovementComponent(s, d, false) {}

	MovementComponent() 
		: MovementComponent(1.0f, Vector2<float>(0, 0)) {}

	bool is_static;
	float speed;
	Vector2<float> direction;

	std::string getName() override { return "movement"; }
};

#endif