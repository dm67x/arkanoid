#ifndef SHIP_ENTITY_H
#define SHIP_ENTITY_H

#include "Entity/entity.h"

namespace Entities
{
    class Ship : public Entity
    {
    public:
        Ship(EntityManager * manager);
    };
}

#endif