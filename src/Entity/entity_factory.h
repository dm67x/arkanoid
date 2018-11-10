#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "singleton.h"
#include "entity.h"
#include "entity_pool.h"
#include <memory>

class EntityFactory : public Singleton<EntityFactory>
{

private:
    EntityPool * pool;

public:
    EntityFactory();
    ~EntityFactory();

    std::shared_ptr<Entity> create(std::string id, std::string name);

};

#endif
