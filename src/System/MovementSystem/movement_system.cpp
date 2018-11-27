#include "movement_system.h"
#include "EventManager/event_manager.h"

void MovementSystem::input(SDL_Event e) {
    if (e.type == SDL_MOUSEMOTION)
        event_manager->trigger("move_ship", &e);
}
    
void MovementSystem::update(float deltaTime) {
    for (auto entity : pool->all()) {
        entity->move();
    }
}

void MovementSystem::draw(SDL_Surface & surface) {

}