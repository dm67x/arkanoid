#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>

class Entity;

class EntityManager
{
private:
    std::vector<Entity *> entities;

public:
    EntityManager();
    ~EntityManager();

    void add(Entity * e);
    void remove(unsigned int id);
    inline const std::vector<Entity *> get() const { return entities; }
};

#endif