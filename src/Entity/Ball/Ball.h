#ifndef BALL_H
#define BALL_H

#include "Entity/Entity.h"

class Ball : public Entity
{

public:
    Ball();

    void init();
    void update();
    void draw();

};

#endif // BALL_H
