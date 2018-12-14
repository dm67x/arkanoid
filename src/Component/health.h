#ifndef HEALTH_COMPONENT_H
#define HEALTH_COMPONENT_H

#include "component.h"

namespace Components
{
    class Health : public Component
    {
    public:
        Health() : life(1), invicible(false) {}
        int life;
        bool invicible;

        std::string name() const override { return "health"; }
    };
}

#endif