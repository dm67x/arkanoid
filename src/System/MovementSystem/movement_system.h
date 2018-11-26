#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "System/system.h"

class MovementSystem : public System
{
private:

public:
    MovementSystem();
    void input(SDL_Event e) override;
    void update(float deltaTime) override;
    void draw(SDL_Surface & surface) override;
};

#endif