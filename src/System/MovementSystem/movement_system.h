#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "System/system.h"

class MovementSystem : public System
{
public:
    void input(SDL_Event e) override;
    void update(float deltaTime) override;
};

#endif