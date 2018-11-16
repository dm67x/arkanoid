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
    int _hit;
    int _points;
    bool _can_be_destroyed;
    PowerUp * _bonus;

public:
    Wall();
    ~Wall() override;

    void hit();


    void setHit(int hit);
    void setPoints(int points);
    void destroyable();
    void indestructible();
    void setBonus(PowerUp & power);

    int getHit();
    int getPoints();
    bool isDestroyable();
    PowerUp * getBonus();

};

}

#endif // ENTITY_WALL_H
