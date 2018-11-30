#include "movement_system.h"
#include "EventManager/event_manager.h"
#include "Entity/dynamic_entity.h"

void MovementSystem::input(SDL_Event e) {
    if (e.type == SDL_MOUSEMOTION)
        event_manager->trigger("move_ship", &e);
}
    
void MovementSystem::update(float deltaTime) {
	if (!pool) return;

	DynamicEntity * dynamic = nullptr;
	Vector2<float> position, direction;
	float speed;
	
	for (auto entity : pool->all()) {
		dynamic = dynamic_cast<DynamicEntity *>(entity);
		if (dynamic) {
			position = dynamic->getPosition();
			direction = dynamic->getDirection();
			speed = dynamic->getSpeed();

			position = position + direction * (speed * 60.0f * deltaTime);

			dynamic->setPosition(position);
		}
    }
}