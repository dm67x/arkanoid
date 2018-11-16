/**
 * @file entity_factory.cpp
 * @version 1
 */

#include "entity_factory.h"
#include "Entity/Ship/ship.h"
#include "Entity/Ball/ball.h"
#include "Entity/Wall/wall.h"

Entity * EntityFactory::create(std::string type) {
    Entity * entity = nullptr;

    if (type.compare("ball") == 0) {
        entity = new Entities::Ball();
    } else if (type.compare("ship") == 0) {
        entity = new Entities::Ship();
    } else if (type.compare("wall") == 0) {
        entity = new Entities::Wall();
    }

	_entities.push_back(entity);

    return entity;
}

std::vector<Entity*> EntityFactory::getEntities() {
	return _entities;
}
