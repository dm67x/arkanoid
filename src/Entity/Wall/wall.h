/**
  * @file wall.h
  * @version 1
  */

#ifndef ENTITY_WALL_H
#define ENTITY_WALL_H

#include "Entity/entity.h"
#include "PowerUp/power_up.h"

namespace Entities
{

/**
 * @brief The Wall class
 */
class Wall : public Entity
{

private:
    PowerUp * _bonus;

public:
    Wall();
    ~Wall() override;

    void setBonus(PowerUp & power);
    PowerUp * getBonus();

};

}

#endif // ENTITY_WALL_H
