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
		: Component(entity), transform(t), render(r), q(0) {
	}

	TransformComponent * transform;
	RenderComponent * render;
	int q; // pour jouer avec la bounding box de la balle

	inline bool collide(CollisionComponent & c) const {
		SDL_Rect box = getBoundingBox();
		SDL_Rect other_box = c.getBoundingBox();

		return (other_box.w > box.x
			&& other_box.h > box.y
			&& other_box.x < box.w
			&& other_box.y < box.h);
	}

	inline SDL_Rect getBoundingBox() const {
		SDL_Rect box;
		box.x = transform->position.x - render->src.w / 2 + q;
		box.y = transform->position.y - render->src.h / 2 + q;
		box.w = transform->position.x + render->src.w / 2 - q;
		box.h = transform->position.y + render->src.h / 2 - q;
		return box;
	}

	std::string getName() override { return "collision"; }
};

#endif