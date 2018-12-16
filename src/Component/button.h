#ifndef BUTTON_COMPONENT_H
#define BUTTON_COMPONENT_H

#include "component.h"

namespace Components
{
    class Button : public Component
    {
    public:
        std::string action; // action de l'event manager

        std::string name() const override { return "button"; }
    };
}

#endif