#ifndef SHIP_H
#define SHIP_H

#include "Entity/Entity.h"

class Ship : public Entity
{

public:
    Ship();

    void init();
    void update();
    void draw();

};

#endif // SHIP_H
