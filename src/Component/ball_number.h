#ifndef BALL_NUMBER_COMPONENT_H
#define BALL_NUMBER_COMPONENT_H

#include "component.h"

namespace Components
{
    class BallNumber : public Component
    {
    public:
        int number;

        std::string name() const override { return "ball_number"; }
    };
}

#endif