#ifndef HIT_COMPONENT_H
#define HIT_COMPONENT_H

#include "component.h"

class HitComponent : public Component
{
public:
	HitComponent(int hit, bool destructible) 
		: Component(), hit(hit), destructible(destructible) {}
	HitComponent() : HitComponent(2, true) {}

	int hit;
	bool destructible;

	std::string getName() override { return "hit"; }
};

#endif