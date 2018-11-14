#include "entity.h"
#include "Component/Components/collision.h"
#include "Component/Components/graphic.h"
#include "Component/Components/position.h"

ComponentPool * Entity::components_pool = Singleton<ComponentPool>::getInstance();

Entity::Entity(std::string name, std::string type) {
    this->name = name;
    this->type = type;
    this->components.clear();
}

Entity::~Entity() {
    for (auto c : components) {
        remove(c);
    }
}

void Entity::add(std::shared_ptr<Component> component) {
    std::string id = component.get()->getName() + "_" + this->type + "_" + this->name;
    auto comp = components_pool->get(id);
    if (comp == nullptr) {
        components_pool->add(id, component);
        components.push_back(component);
        return;
    }

    components.push_back(comp);
}

void Entity::remove(std::shared_ptr<Component> component) {
    std::string id = component.get()->getName() + "_" + this->type + "_" + this->name;

    for (auto it = components.begin(); it != components.end(); it++) {
        if (*it == component)
            components.erase(it);
    }

    components_pool->remove(id);
}

std::vector<std::shared_ptr<Component>> Entity::getComponents() {
    return components;
}

std::shared_ptr<Component> Entity::findComponent(std::string type) {
    Component * comp;
    for (auto c : getComponents()) {
        comp = c.get();
        if (comp->getName() == type) {
            return c;
        }
    }

    return nullptr;
}
