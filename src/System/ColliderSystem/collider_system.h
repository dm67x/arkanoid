#ifndef COLLIDER_SYSTEM_H
#define COLLIDER_SYSTEM_H

#include "System/system.h"

class ColliderSystem : public System
{
public:
    void input(SDL_Event e) override;
    void update(float deltaTime) override;
    void draw(SDL_Surface & surface) override;
};

#endif