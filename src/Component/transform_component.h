#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "component.h"
#include "vector2.h"

class TransformComponent : public Component
{
public:
	TransformComponent(Vector2<float> p, Vector2<float> s) 
		: Component(), position(p), scale(s) {}
	
	TransformComponent() 
		: TransformComponent(Vector2<float>(0, 0), Vector2<float>(1, 1)) {}

	Vector2<float> position;
	Vector2<float> scale;

	std::string getName() override { return "transform"; }
};

#endif