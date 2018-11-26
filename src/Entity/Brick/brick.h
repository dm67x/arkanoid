#ifndef BRICK_ENTITY_H
#define BRICK_ENTITY_H

#include "Entity/static_entity.h"

namespace Entities
{
    class Brick : public StaticEntity
    {
    private:
        int hit; // number of hits to destroy
        bool destructible; // can be destroyed
        // power up

    public:
        Brick();
        Brick(int hit);
        ~Brick() override;

        void setHit(int hit);
        void damage(int force = 1);
        void makeDestructible();
        void makeInvicible();

        std::string getType() override;
    };
}

#endif