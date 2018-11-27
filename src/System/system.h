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

    System();

public:
    virtual void input(SDL_Event e);
    virtual void update(float deltaTime);
    virtual void draw(SDL_Surface & surface);
};

#endif