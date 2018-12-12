#ifndef SHIP_ENTITY_H
#define SHIP_ENTITY_H

#include "EntityManager/entity_manager.h"

namespace Entities
{
    class Ship
    {
    private:
        Entity id;
        EntityManager * manager;

    public:
        Ship(EntityManager * manager);
        ~Ship();

        Components::Transform * transform;
        Components::Sprite * sprite;
    };
}

#endif