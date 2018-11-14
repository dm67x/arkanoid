#include "component_pool.h"

ComponentPool::ComponentPool() {
    components.clear();
}

ComponentPool::~ComponentPool() {

}

void ComponentPool::add(std::string id, std::shared_ptr<Component> c) {
    if (get(id) != nullptr) return;
    components.insert(std::make_pair(id, c));
}

void ComponentPool::remove(std::string id) {
    if (get(id) == nullptr) return;
    components.erase(components.find(id));
}

std::shared_ptr<Component> ComponentPool::get(std::string id) {
    auto it = components.find(id);
    if (it != components.end()) return it->second;
    return nullptr;
}


