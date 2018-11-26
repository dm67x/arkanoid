#ifndef SYSTEM_H
#define SYSTEM_H

#include "Entity/entity_pool.h"
#include <SDL.h>

class System
{
protected:
    static EntityPool * pool;

public:
    virtual void update(float deltaTime) = 0;
    virtual void draw(SDL_Surface & surface) = 0;
};

#endif