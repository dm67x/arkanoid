#include "entity_factory.h"
#include "Entity/Ship/ship.h"
#include "Entity/Brick/brick.h"
#include "entity_pool.h"

Entity * EntityFactory::build(std::string type) {
    Entity * entity = nullptr;
    
    if (type == "brick") entity = new Entities::Brick();
    else if (type == "ship") entity = new Entities::Ship();

    if (entity)
        Singleton<EntityPool>::getInstance()->add(*entity);

    return entity;
}