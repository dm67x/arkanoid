#ifndef COMPONENT_COLLISION_H
#define COMPONENT_COLLISION_H

#include "Component/component.h"

namespace Components
{

class Collision : public Component
{

public:
    Collision();
    ~Collision();
    std::string getName();

};

}

#endif
