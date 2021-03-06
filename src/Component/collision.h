#ifndef COLLISION_COMPONENT_H
#define COLLISION_COMPONENT_H

#include "component.h"
#include <SDL2/SDL.h>

namespace Components
{
    class Collision : public Component
    {
    public:
        std::string name() const override { return "collision"; }
    };
}

#endif