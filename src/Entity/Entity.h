#ifndef ENTITY_H
#define ENTITY_H

#include "Window/Window.h"

class Entity
{

protected:
    Window * _window;
    SDL_Rect _destRect, _srcRect;

    static SDL_Surface * _entitiesSurface;

    Entity();

public:
    virtual ~Entity();

    void add(Window * window);

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

};

#endif // ENTITY_H
