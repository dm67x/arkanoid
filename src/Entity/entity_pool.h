#ifndef ENTITY_POOL_H
#define ENTITY_POOL_H

#include "singleton.h"
#include "entity.h"
#include <vector>

class EntityPool : public Singleton<EntityPool>
{
private:
    std::vector<Entity *> entities;

public:
    void add(Entity & e);
    void remove(Entity & e);
    void clear();
    inline std::vector<Entity *> all() const { return entities; }
};

#endif