/**
 * @file ship.h
 * @version 1
 */

#ifndef ENTITY_SHIP_H
#define ENTITY_SHIP_H

#include "Entity/entity.h"

namespace Entities
{

class Ship : public Entity
{

public:
    Ship();
    ~Ship() override;

};

};

#endif // ENTITY_SHIP_H
