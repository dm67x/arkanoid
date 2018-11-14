#ifndef COMPONENT_VELOCITY_H
#define COMPONENT_VELOCITY_H

#include "Component/component.h"
#include <SDL.h>

namespace Components
{

class Velocity : public Component
{

private:
    int speed;
    int directionX, directionY;

public:
    Velocity(int directionX, int directionY);
    Velocity(int speed, int directionX, int directionY);
    ~Velocity();

    SDL_Rect getVelocity();
    std::string getName();

};

}

#endif // COMPONENT_VELOCITY_H
