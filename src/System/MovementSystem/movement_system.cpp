#include "movement_system.h"
#include "EventManager/event_manager.h"
#include "Component/transform_component.h"
#include "Component/movement_component.h"
#include "Component/type_component.h"

void MovementSystem::input(SDL_Event e) {
	if (e.type == SDL_MOUSEMOTION) {
		EntityPool * pool = current_scene->getPool();
		TransformComponent * tc = nullptr;
		TypeComponent * tyc = nullptr;
		MovementComponent * mc = nullptr;

		for (auto ent : pool->getEntities()) {
			for (auto comp : ent.second) {
				if (comp->getName() == "type")
					tyc = static_cast<TypeComponent *>(comp);
				else if (comp->getName() == "transform")
					tc = static_cast<TransformComponent *>(comp);
				else if (comp->getName() == "movement")
					mc = static_cast<MovementComponent *>(comp);
			}

			if (tc && tyc) {
				if (tyc->type == "ball") {
					if (mc && mc->is_static) {
						tc->position.x = e.motion.x;
					}
				}
				else if (tyc->type == "ship") {
					tc->position.x = e.motion.x;
				}
			}

			tc = nullptr;
			tyc = nullptr;
			mc = nullptr;
		}
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN) {
		EntityPool * pool = current_scene->getPool();
		MovementComponent * mc = nullptr;
		TypeComponent * tyc = nullptr;

		for (auto ent : pool->getEntities()) {
			for (auto comp : ent.second) {
				if (comp->getName() == "movement")
					mc = static_cast<MovementComponent *>(comp);
				else if (comp->getName() == "type")
					tyc = static_cast<TypeComponent *>(comp);
			}

			if (tyc && tyc->type == "ball" && mc) {
				if (mc->is_static) {
					mc->is_static = false;
					mc->direction = Vector2<float>(0, -1);
				}
			}

			tyc = nullptr;
			mc = nullptr;
		}
	}
}
    
void MovementSystem::update(float deltaTime) {
	if (!current_scene) return;

	EntityPool * pool = current_scene->getPool();
	TransformComponent * tc = nullptr;
	MovementComponent * mc = nullptr;

	for (auto entity : pool->getEntities()) {
		for (auto comp : entity.second) {
			if (comp->getName() == "transform") {
				tc = static_cast<TransformComponent *>(comp);
			}
			else if (comp->getName() == "movement") {
				mc = static_cast<MovementComponent *>(comp);
			}
		}

		if (tc && mc) {
			if (!mc->is_static) {
				tc->position = tc->position + mc->direction * (mc->speed * 60.0f * deltaTime);
			}
		}

		tc = nullptr;
		mc = nullptr;
	}
}
