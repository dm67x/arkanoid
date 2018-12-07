#include "scene.h"
#include "System/system.h"

EventManager * Scene::event_manager = Singleton<EventManager>::getInstance();
EntityFactory * Scene::entity_factory = Singleton<EntityFactory>::getInstance();

Scene::Scene(const std::string name) 
	: name(name), width(0), height(0) {
}

Scene::~Scene() {
	for (auto system : systems) {
		delete system;
	}

	for (auto ent : entities) {
		delete ent;
	}

	systems.clear();
	entities.clear();
}

void Scene::setSize(int w, int h) {
	width = w;
	height = h;
}

void Scene::destroyEntity(Entity & e)
{
	for (auto it = entities.begin(); it != entities.end(); it++) {
		if ((*it)->getID() == e.getID()) {
			entities.erase(it);
			break;
		}
	}
}

void Scene::addEntity(Entity & e)
{
	entities.push_back(&e);
}
