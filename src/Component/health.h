#ifndef HEALTH_COMPONENT_H
#define HEALTH_COMPONENT_H

#include "component.h"

namespace Components
{
    class Health : public Component
    {
    public:
        int life;

        std::string name() const override { return "health"; }
    };
}

#endif