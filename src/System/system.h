#ifndef SYSTEM_H
#define SYSTEM_H

#include "Entity/entity_pool.h"

class System
{

protected:
    static EntityPool * entity_pool;

    System();

public:
    ~System();

};

#endif
