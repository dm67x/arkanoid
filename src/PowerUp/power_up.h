/**
  * @file power_up.h
  * @version 1
  */

#ifndef POWER_UP_H
#define POWER_UP_H

#include "Entity/entity.h"

/**
 * @brief The PowerUp class
 */
class PowerUp
{

protected:
    Entity * _operate_on;

    PowerUp();

public:
    virtual ~PowerUp();
    virtual void activate() = 0;

};

#endif // POWER_UP_H
