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

private:
    double _speed;
    Vector2<int> _direction;

public:
    Ball();
    ~Ball() override;

    void setDirection(Vector2<int> _direction);

};

}

#endif // ENTITY_BALL_H
