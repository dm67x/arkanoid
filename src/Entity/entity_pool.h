#ifndef ENTITY_POOL_H
#define ENTITY_POOL_H

#include "entity.h"
#include <vector>

class EntityPool
{
private:
    std::vector<Entity *> entities;

public:
    void add(Entity & e);
    void remove(Entity & e);
    void clear();
    std::vector<Entity *> all(std::string type) const;
    inline std::vector<Entity *> all() const { return entities; }
};

#endif