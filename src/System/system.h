#ifndef SYSTEM_H
#define SYSTEM_H

#include "Entity/entity_pool.h"
#include <SDL.h>
#include "EventManager/event_manager.h"

class System
{
protected:
    static EntityPool * pool;
    static EventManager * event_manager;

public:
    virtual void input(SDL_Event e) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void draw(SDL_Surface & surface) = 0;
};

#endif