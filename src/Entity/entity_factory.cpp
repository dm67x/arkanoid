#include "entity_factory.h"
#include "Entities/ball.h"
#include "Entities/ship.h"

EntityFactory::EntityFactory() {
    pool = Singleton<EntityPool>::getInstance();
}

EntityFactory::~EntityFactory() {
}

std::shared_ptr<Entity> EntityFactory::create(std::string id, std::string name) {
    std::shared_ptr<Entity> entity = pool->get(id);
    if (entity) return entity;

    if (name == "ball") {
        entity = std::make_shared<Entities::Ball>(id);
    } else if (name == "ship") {
        entity = std::make_shared<Entities::Ship>(id);
    } else if (name == "block") {

    }

    pool->add(id, entity);
    return entity;
}
