#ifndef COLLISION_COMPONENT_H
#define COLLISION_COMPONENT_H

#include <SDL.h>

#include "component.h"
#include "transform_component.h"
#include "render_component.h"

class CollisionComponent : public Component
{
public:
	CollisionComponent(Entity entity, TransformComponent * t, RenderComponent * r) 
		: Component(entity), transform(t), render(r) {
	}

	TransformComponent * transform;
	RenderComponent * render;

	inline bool collide(SDL_Rect other_box) const {
		SDL_Rect box = getBoundingBox();

		return (other_box.w > box.x
			&& other_box.h > box.y
			&& other_box.x < box.w
			&& other_box.y < box.h);
	}

	inline SDL_Rect getBoundingBox() const {
		SDL_Rect box;
		box.x = transform->position.x - render->src.w / 2;
		box.y = transform->position.y - render->src.h / 2;
		box.w = render->src.w;
		box.h = render->src.h;
		return box;
	}

	std::string getName() override { return "collision"; }
};

#endif