#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "component.h"
#include "vector2.h"

namespace Components
{
    class Transform : public Component
    {
    public:
        Transform() 
            : position(Vector2<float>(0, 0)), scale(Vector2<float>(1, 1)) {}

        Vector2<float> position;
        Vector2<float> scale;

        std::string name() const override { return "transform"; }
    };
}

#endif