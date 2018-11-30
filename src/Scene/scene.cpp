#include "scene.h"

EventManager * Scene::event_manager = Singleton<EventManager>::getInstance();
EntityFactory * Scene::entity_factory = Singleton<EntityFactory>::getInstance();

Scene::Scene(const std::string name) : name(name), width(0), height(0) {
}

Scene::~Scene() {
	for (auto system : systems) {
		delete system;
	}

	systems.clear();
}

void Scene::reload() {
	EntityFactory::setPool(pool);
	System::setPool(pool);
}

void Scene::setSize(int w, int h) {
	width = w;
	height = h;
}