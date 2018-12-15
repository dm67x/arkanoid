#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>

#include "EventManager/event_manager.h"
#include "Scene/scene.h"

class System
{
protected:
	Scene * current;
    static EventManager * event_manager;

    System();

public:
    virtual void input(SDL_Event e);
    virtual void update(double deltaTime);
    virtual void draw(SDL_Surface & surface);
};

#endif