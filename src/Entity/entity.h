#ifndef ENTITY_H
#define ENTITY_H

#include "Entity/entity_pool.h"
#include "Component/transform_component.h"
#include "Component/type_component.h"

class Entity
{
protected:
    EntityPool * pool;
    uint32_t id;

    Entity(uint32_t id, EntityPool * pool, std::string t);
    virtual ~Entity();

public:
    TransformComponent * transform;
	TypeComponent * type;
};

#endif