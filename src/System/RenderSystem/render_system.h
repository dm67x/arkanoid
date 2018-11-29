#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "System/system.h"

class RenderSystem : public System
{
private:
    SDL_Surface * sprite;

public:
    RenderSystem(SDL_Surface * sprite);
    void draw(SDL_Surface & surface) override;
};

#endif