#include "entity_pool.h"

void EntityPool::add(Entity & e) {
    entities.push_back(&e);
}

void EntityPool::remove(Entity & e) {
    for (auto it = entities.begin(); it != entities.end(); it++) {
        if ((*it)->getID() == e.getID()) {
            entities.erase(it);
            break;
        }
    }
}

void EntityPool::clear() {
    entities.clear();
}