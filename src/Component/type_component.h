#ifndef TYPE_COMPONENT_H
#define TYPE_COMPONENT_H

#include "component.h"

class TypeComponent : public Component
{
public:
	TypeComponent(Entity id, std::string type) : Component(id), type(type) {}

	std::string type;
	std::string getName() override { return "type"; }
};

#endif