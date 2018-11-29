#ifndef BALL_ENTITY_H
#define BALL_ENTITY_H

#include "Entity/dynamic_entity.h"

namespace Entities
{
    class Ball : public DynamicEntity
    {
    public:
        Ball();
        ~Ball() override;

        std::string getType() override;
    };
}

#endif