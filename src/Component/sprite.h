#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "component.h"
#include <SDL2/SDL.h>

namespace Components
{
    class Sprite : public Component
    {
    public:
        SDL_Rect src;

        std::string name() const override { return "sprite"; }
    };
}

#endif