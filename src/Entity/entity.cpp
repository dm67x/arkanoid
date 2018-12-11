#include "entity.h"

Entity::Entity(uint32_t id, EntityPool * pool, std::string t) 
        : id(id), pool(pool) 
{
    transform = new TransformComponent();
    type = new TypeComponent(t);
    pool->add(id, *type);
    pool->add(id, *transform);
}

Entity::~Entity() {
    pool->remove(id);
}