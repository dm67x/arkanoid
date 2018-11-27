#include "system.h"

EntityPool * System::pool = Singleton<EntityPool>::getInstance();
EventManager * System::event_manager = Singleton<EventManager>::getInstance();

System::System() {}
void System::input(SDL_Event e) {}
void System::update(float deltaTime) {}
void System::draw(SDL_Surface & surface) {}