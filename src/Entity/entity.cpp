#include "entity.h"
#include "EntityManager/entity_manager.h"

unsigned int Entity::next_id = 0;

Entity::Entity()
{
    id = next_id++;
    Singleton<EntityManager>::getInstance()->add(this);
    active = false;
}

Entity::~Entity() {
    Singleton<EntityManager>::getInstance()->remove(id);
    for (auto c : components) delete c;
    components.clear();
}

void Entity::add(Component * c) {
    components.push_back(c);
}

void Entity::remove(std::string name) {
    for (auto it = components.begin(); it != components.end(); it++) {
        if ((*it)->name() == name) {
            delete *it;
            components.erase(it);
            break;
        }
    }
}

void Entity::setActive(bool active) {
    this->active = active;
}