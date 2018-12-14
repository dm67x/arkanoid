#include "entity_manager.h"
#include "EventManager/event_manager.h"
#include "Entity/entity.h"

#include <iostream>

EntityManager::EntityManager() {
}

EntityManager::~EntityManager() {
    for (auto entity : entities) delete entity;
}

void EntityManager::add(Entity * e) {
    entities.push_back(e);
}

void EntityManager::remove(unsigned int id) {
    std::cout << id << std::endl;
    for (auto it = entities.begin(); it != entities.end(); it++) {
        if ((*it)->getID() == id) {
            entities.erase(it);
            return; 
        }
    }
}