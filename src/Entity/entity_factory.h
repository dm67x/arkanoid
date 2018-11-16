/**
  * @file entity_factory.h
  * @version 1
  */

#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "singleton.h"
#include "entity.h"
#include <vector>

/**
 * @brief The EntityFactory class
 */
class EntityFactory : Singleton<EntityFactory>
{

private:
	std::vector<Entity *> _entities;

public:
    Entity * create(std::string type);

	std::vector<Entity *> getEntities();

};

#endif // ENTITY_FACTORY_H
