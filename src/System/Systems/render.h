#ifndef SYSTEM_RENDER_H
#define SYSTEM_RENDER_H

#include "System/system.h"
#include <SDL.h>

namespace Systems
{

class Render : public System
{

public:
    Render();
    ~Render();

    void update(float dt);
    void draw(SDL_Surface & surface);

};

}

#endif
