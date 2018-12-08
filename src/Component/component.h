#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>

#include "Entity/entity.h"

class Component
{
private:
	Entity entity_id;

protected:
	Component(Entity entity) : entity_id(entity) {}

public:
	virtual std::string getName() = 0;
};

#endif