#ifndef BRICK_ENTITY_H
#define BRICK_ENTITY_H

#include "EntityManager/entity_manager.h"

namespace Entities
{
    class Brick
    {
    private:
        Entity id;
        EntityManager * manager;

    public:
        Brick(EntityManager * manager);
        ~Brick();

        Components::Transform * transform;
        Components::Sprite * sprite;
        Components::Health * health;
        Components::Points * points;
    };
}

#endif