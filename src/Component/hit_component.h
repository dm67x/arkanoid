#ifndef HIT_COMPONENT_H
#define HIT_COMPONENT_H

#include "component.h"

class HitComponent : public Component
{
public:
	HitComponent(Entity id, int hit, bool destructible) 
		: Component(id), hit(hit), destructible(destructible) {}
	HitComponent(Entity id) : HitComponent(id, 2, true) {}

	int hit;
	bool destructible;

	std::string getName() override { return "hit"; }
};

#endif