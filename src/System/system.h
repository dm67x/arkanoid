#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>

#include "EventManager/event_manager.h"
#include "Scene/scene.h"
#include "EntityManager/entity_manager.h"

class System
{
private:
    bool active;

protected:
	Scene * current;
    static EntityManager * entity_manager;
    static EventManager * event_manager;

    System();

public:
    virtual void input(SDL_Event e);
    virtual void update(double deltaTime);
    virtual void draw(SDL_Surface & surface);

    void setActive(bool active);
    inline const bool isActive() { return active; }
};

#endif