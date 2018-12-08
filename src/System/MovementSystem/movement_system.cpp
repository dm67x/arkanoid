#include "movement_system.h"
#include "EventManager/event_manager.h"
#include "Component/transform_component.h"
#include "Component/movement_component.h"

void MovementSystem::input(SDL_Event e) {
	if (e.type == SDL_MOUSEMOTION) {
		event_manager->trigger("move_ball_with_ship", &e);
		event_manager->trigger("move_ship", &e);
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN) {
		event_manager->trigger("launch_ball", nullptr);
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

	/*DynamicEntity * dynamic = nullptr;
	Vector2<float> position, direction;
	float speed;
	
	for (auto entity : current_scene->getEntities()) {
		dynamic = dynamic_cast<DynamicEntity *>(entity);
		if (dynamic && dynamic->canMove()) {
			position = dynamic->getPosition();
			direction = dynamic->getDirection();
			speed = dynamic->getSpeed();

			position = position + direction * (speed * 60.0f * deltaTime);

			dynamic->setPosition(position);
		}
    }*/
}
