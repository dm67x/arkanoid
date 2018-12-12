#ifndef MOTION_COMPONENT_H
#define MOTION_COMPONENT_H

#include "component.h"
#include "vector2.h"

namespace Components
{
    class Motion : public Component
    {
    public:
        Vector2<float> velocity;

        std::string name() const override { return "motion"; }
    };
}

#endif