#include "entity.h"

ComponentPool * Entity::components_pool = Singleton<ComponentPool>::getInstance();

Entity::Entity(std::string name) {
    this->name = name;
    this->components.clear();
}

Entity::~Entity() {

}

void Entity::add(std::shared_ptr<Component> component) {
    std::string id = component.get()->getName() + "_" + this->name;
    auto comp = components_pool->get(id);
    if (comp == nullptr) {
        components_pool->add(id, component);
        this->components.push_back(component);
        return;
    }

    this->components.push_back(comp);
}

void Entity::remove(std::shared_ptr<Component> component) {
    // TODO
}

std::vector<std::shared_ptr<Component>> Entity::getComponents() {
    return components;
}
