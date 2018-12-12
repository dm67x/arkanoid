#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "component.h"
#include "vector2.h"

namespace Components
{
    class Transform : public Component
    {
    public:
        Vector2<float> position;
        Vector2<float> scale;

        std::string name() const override { return "transform"; }
    };
}

#endif