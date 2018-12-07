#include "system.h"

Scene * System::current_scene = nullptr;
EventManager * System::event_manager = Singleton<EventManager>::getInstance();

System::System() {}
void System::input(SDL_Event e) {}
void System::update(float deltaTime) {}
void System::draw(SDL_Surface & surface) {}

void System::setScene(Scene & s) {
	current_scene = &s;
}