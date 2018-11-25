/**
 * @file ball.h
 * @version 1
 */

#ifndef ENTITY_BALL_H
#define ENTITY_BALL_H

#include "Entity/entity.h"

namespace Entities
{

class Ball : public Entity
{

public:
    Ball();
    ~Ball() override;

};

}

#endif // ENTITY_BALL_H
