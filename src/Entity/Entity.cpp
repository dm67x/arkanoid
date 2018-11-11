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

}

void Entity::add(std::shared_ptr<Component> component) {
    std::string id = component.get()->getName() + "_" + this->type + "_" + this->name;
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

std::shared_ptr<Component> Entity::findComponent(std::string type) {
    for (auto c : getComponents()) {
        Component * comp = c.get();
        if (type == "position") {
            if (dynamic_cast<Components::Position *>(comp)) return c;
        } else if (type == "graphic") {
            if (dynamic_cast<Components::Graphic *>(comp)) return c;
        } else if (type == "collision") {
            if (dynamic_cast<Components::Collision *>(comp)) return c;
        }
    }

    return nullptr;
}
