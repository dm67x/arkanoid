#include "entity.h"

unsigned int Entity::next_id = 0;

Entity::Entity(EntityManager * manager)
    : manager(manager)
{
    id = next_id++;
    manager->add(this);
}

Entity::~Entity() {
    manager->remove(id);
    for (auto c : components) delete c;
    components.clear();
}

void Entity::add(Component * c) {
    components.push_back(c);
}

Component * Entity::get(std::string name) {
    for (auto it = components.begin(); it != components.end(); it++) {
        if ((*it)->name() == name) {
            return *it;
        }
    }
    return nullptr;
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