#ifndef POINTS_COMPONENT_H
#define POINTS_COMPONENT_H

#include "component.h"

namespace Components
{
    class Points : public Component
    {
    public:
        int points;

        std::string name() const override { return "points"; }
    };
}

#endif