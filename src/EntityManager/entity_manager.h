#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "Entity/entity.h"
#include "ComponentManager/component_manager.h"

#include <vector>

class EntityManager
{
private:
    std::vector<Entity> entities;
    Entity id;
    ComponentManager * component_manager;

public:
    EntityManager();
    ~EntityManager();

    Entity createEntity();
    void removeEntity(Entity id);
    Component * addComponent(Entity id, std::string type);

    inline const std::vector<Entity> getEntities() const { return entities; }
};

#endif