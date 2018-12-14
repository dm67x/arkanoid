#ifndef POINTS_COMPONENT_H
#define POINTS_COMPONENT_H

#include "component.h"

namespace Components
{
    class Points : public Component
    {
    public:
        Points() : points(0) {}

        int points;

        std::string name() const override { return "points"; }
    };
}

#endif