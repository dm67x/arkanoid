#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

#include "EntityManager/entity_manager.h"
#include "Component/component.h"

class Entity
{
private:
    static unsigned int next_id;
    unsigned int id;
    EntityManager * manager;
    std::vector<Component *> components;

public:
    Entity(EntityManager * manager);
    virtual ~Entity();

    void add(Component * c);
    void remove(std::string name);
    Component * get(std::string name);

    inline std::vector<Component *> getComponents() { return components; }
    inline const unsigned int getID() { return id; }
};

#endif