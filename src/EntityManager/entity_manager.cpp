#include "entity_manager.h"
#include "EventManager/event_manager.h"

EntityManager::EntityManager() {
    id = 0;
    component_manager = Singleton<ComponentManager>::getInstance();
}

EntityManager::~EntityManager() {
    for (auto entity : entities) {
        component_manager->removeComponents(entity);
    }
}

Entity EntityManager::createEntity() {
    Entity current = id++;
    entities.push_back(current);
    return current;
}

void EntityManager::removeEntity(Entity id) {
    for (auto it = entities.begin(); it != entities.end(); it++) {
        if (*it == id) {
            entities.erase(it); 
            component_manager->removeComponents(id);
        }
    }
}

Component * EntityManager::addComponent(Entity id, std::string type) {
    return component_manager->createComponent(id, type);
}