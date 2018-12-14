#include "scene.h"
#include "System/system.h"

EventManager * Scene::event_manager = Singleton<EventManager>::getInstance();

Scene::Scene(const std::string name) 
	: name(name), width(0), height(0) 
{
}

Scene::~Scene() {
	for (auto system : systems) {
		delete system;
	}
	systems.clear();
}

void Scene::setSize(int w, int h) {
	width = w;
	height = h;
}

void Scene::update(double deltaTime) {
	for (auto s : systems) s->update(deltaTime);
}

void Scene::draw(SDL_Surface & surface) {
	SDL_FillRect(&surface, nullptr, 0x000000);
	for (auto s : systems) s->draw(surface);
}

void Scene::input(SDL_Event e) {
	for (auto s : systems) s->input(e);
}
