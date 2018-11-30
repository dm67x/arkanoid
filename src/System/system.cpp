#include "system.h"

EntityPool * System::pool = nullptr;
EventManager * System::event_manager = Singleton<EventManager>::getInstance();

System::System() {}
void System::input(SDL_Event e) {}
void System::update(float deltaTime) {}
void System::draw(SDL_Surface & surface) {}
void System::setPool(EntityPool * p) {
	pool = p;
}