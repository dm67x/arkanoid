#ifndef COLLISION_COMPONENT_H
#define COLLISION_COMPONENT_H

#include <SDL.h>

#include "component.h"

class CollisionComponent : public Component
{
public:
	CollisionComponent(Entity entity, SDL_Rect box) 
		: Component(entity), box(box) {}

	SDL_Rect box;

	inline bool collide(SDL_Rect other_box) const {
		return (other_box.w > box.x
			&& other_box.h > box.y
			&& other_box.x < box.w
			&& other_box.y < box.h);
	}

	std::string getName() override { return "collision"; }
};

#endif