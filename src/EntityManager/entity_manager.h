#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "singleton.h"
#include "Entity/entity.h"
#include <vector>

class EntityManager : public Singleton<EntityManager>
{
private:
    std::vector<Entity *> entities;

public:
    ~EntityManager();

    void add(Entity * e);
    void remove(unsigned int id);
    std::vector<Entity *> get() const;
};

#endif