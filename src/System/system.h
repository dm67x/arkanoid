#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>

#include "EventManager/event_manager.h"
#include "Scene/scene.h"

class System
{
protected:
	static Scene * current_scene;
    static EventManager * event_manager;

    System();

public:
    virtual void input(SDL_Event e);
    virtual void update(float deltaTime);
    virtual void draw(SDL_Surface & surface);

	static void setScene(Scene & s);
};

#endif