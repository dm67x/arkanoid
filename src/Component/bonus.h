#ifndef BONUS_COMPONENT_H
#define BONUS_COMPONENT_H

#include "component.h"

namespace Components
{
    class Bonus : public Component
    {
    public:
        Bonus() : bonus(0) {}

        int bonus; // bonus type (number)

        std::string name() const override { return "bonus"; }
    };
}

#endif