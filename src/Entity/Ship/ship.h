#ifndef SHIP_ENTITY_H
#define SHIP_ENTITY_H

#include "Entity/dynamic_entity.h"

namespace Entities
{
    class Ship : public DynamicEntity
    {
    public:
        Ship();
        ~Ship() override;

        std::string getType() override;
    };
}

#endif