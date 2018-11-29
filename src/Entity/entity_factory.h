#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "singleton.h"
#include "entity.h"

class EntityFactory : public Singleton<EntityFactory>
{
public:
    Entity * build(std::string type);
    void destroy(Entity * e);
};

#endif