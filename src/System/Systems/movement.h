#ifndef SYSTEM_MOVEMENT_H
#define SYSTEM_MOVEMENT_H

#include "System/system.h"
#include <SDL.h>

namespace Systems
{

class Movement : public System
{

public:
    Movement();
    ~Movement();

    void update(float dt);
    void draw(SDL_Surface & surface);

};

}

#endif
