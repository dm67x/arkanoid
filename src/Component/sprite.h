#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "component.h"
#include <SDL2/SDL.h>

namespace Components
{
    class Sprite : public Component
    {
    public:
        Sprite() : src({0, 0, 0, 0}) {}

        SDL_Rect src;

        std::string name() const override { return "sprite"; }
    };
}

#endif