#include "system.h"
#include "Scene/scene_manager.h"

EventManager * System::event_manager = Singleton<EventManager>::getInstance();

System::System() : current(nullptr) {
}

void System::input(SDL_Event e) {
	current = Singleton<SceneManager>::getInstance()->getCurrent();
	if (!current) return;
}

void System::update(double deltaTime) {
	current = Singleton<SceneManager>::getInstance()->getCurrent();
	if (!current) return;
}

void System::draw(SDL_Surface & surface) {
	current = Singleton<SceneManager>::getInstance()->getCurrent();
	if (!current) return;
}