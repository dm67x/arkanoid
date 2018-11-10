#include "entity_pool.h"

EntityPool::EntityPool() {
    entities.clear();
}

EntityPool::~EntityPool() {
}

void EntityPool::add(std::string id, std::shared_ptr<Entity> e) {
    if (get(id) != nullptr) return;
    entities.insert(std::make_pair(id, e));
}

std::shared_ptr<Entity> EntityPool::get(std::string id) {
    auto it = entities.find(id);
    if (it != entities.end()) return it->second;
    return nullptr;
}

std::map<std::string, std::shared_ptr<Entity>> EntityPool::getAll() {
    return entities;
}
