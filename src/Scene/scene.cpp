#include "scene.h"
#include "System/system.h"

EventManager * Scene::event_manager = Singleton<EventManager>::getInstance();

Scene::Scene(const std::string name) 
	: name(name), width(0), height(0) 
{
	pool = new EntityPool();
}

Scene::~Scene() {
	for (auto system : systems) {
		delete system;
	}
	systems.clear();

	delete pool;
}

void Scene::setSize(int w, int h) {
	width = w;
	height = h;
}
