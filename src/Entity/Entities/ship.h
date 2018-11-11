#ifndef ENTITY_SHIP_H
#define ENTITY_SHIP_H

#include "Entity/entity.h"

namespace Entities
{

class Ship : public Entity
{

public:
    Ship(std::string name);
    ~Ship();

};

}

#endif
