#include "movement_system.h"
#include "EventManager/event_manager.h"

MovementSystem::MovementSystem() {
}

void MovementSystem::input(SDL_Event e) {
    if (e.type == SDL_MOUSEMOTION)
        event_manager->trigger("move_ship", &e);
}
    
void MovementSystem::update(float deltaTime) {

}

void MovementSystem::draw(SDL_Surface & surface) {

}