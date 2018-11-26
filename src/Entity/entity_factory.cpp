#include "entity_factory.h"
#include "Entity/Ship/ship.h"
#include "Entity/Brick/brick.h"
#include "Entity/Ball/ball.h"
#include "entity_pool.h"
#include <cassert>

Entity * EntityFactory::build(std::string type) {
    Entity * entity = nullptr;
    
    if (type == "brick") entity = new Entities::Brick();
    else if (type == "ship") entity = new Entities::Ship();
    else if (type == "ball") entity = new Entities::Ball();

    if (entity)
        Singleton<EntityPool>::getInstance()->add(*entity);
    else
        assert("Not a valid entity");

    return entity;
}