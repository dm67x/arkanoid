#ifndef CONTROL_COMPONENT_H
#define CONTROL_COMPONENT_H

#include "component.h"

namespace Components
{
    class Control : public Component
    {
    public:
        std::string name() const override { return "control"; }
    };
}

#endif