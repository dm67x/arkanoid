#include "scene.h"

EventManager * Scene::event_manager = Singleton<EventManager>::getInstance();
EntityFactory * Scene::entity_factory = Singleton<EntityFactory>::getInstance();

Scene::Scene(const std::string name) : name(name) {
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