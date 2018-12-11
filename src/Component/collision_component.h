#ifndef COLLISION_COMPONENT_H
#define COLLISION_COMPONENT_H

#include <SDL2/SDL.h>

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
		box.x = static_cast<int>(transform->position.x) - static_cast<int>((render->src.w / 2 + q) * transform->scale.x);
		box.y = static_cast<int>(transform->position.y) - static_cast<int>((render->src.h / 2 + q) * transform->scale.y);
		box.w = static_cast<int>(transform->position.x) + static_cast<int>((render->src.w / 2 - q) * transform->scale.x);
		box.h = static_cast<int>(transform->position.y) + static_cast<int>((render->src.h / 2 - q) * transform->scale.y);
		return box;
	}

	std::string getName() override { return "collision"; }
};

#endif