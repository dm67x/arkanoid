#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "singleton.h"
#include "entity.h"
#include "Entity/entity_pool.h"

class EntityFactory : public Singleton<EntityFactory>
{
private:
	static EntityPool * pool;

public:
    Entity * build(std::string type);
    void destroy(Entity * e);

	static void setPool(EntityPool * p);
};

#endif