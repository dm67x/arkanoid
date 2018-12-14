#ifndef BALL_ENTITY_H
#define BALL_ENTITY_H

#include "Entity/entity.h"

namespace Entities
{
    class Ball : public Entity
    {
    public:
        Ball(EntityManager * manager);
    };
}

#endif