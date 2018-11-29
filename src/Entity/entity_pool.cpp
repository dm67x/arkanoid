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

std::vector<Entity *> EntityPool::all(std::string type) const {
    std::vector<Entity *> ent;
    for (auto e : entities) {
        if (e->getType() == type)
            ent.push_back(e);
    }
    return ent;
}