#ifndef BALL_ENTITY_H
#define BALL_ENTITY_H

#include "EntityManager/entity_manager.h"

namespace Entities
{
    class Ball
    {
    private:
        Entity id;
        EntityManager * manager;

    public:
        Ball(EntityManager * manager);
        ~Ball();

        Components::Transform * transform;
        Components::Sprite * sprite;

    };
}

#endif