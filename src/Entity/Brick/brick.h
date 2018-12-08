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
		int points;
        // power up

		void setGraphicWithPoints();

    public:
		Brick();
        Brick(int points);
        Brick(int points, int hit);
        ~Brick() override;

        void setHit(int hit);
        void damage(int force = 1);
        void makeDestructible();
        void makeInvicible();
		void setPoints(int pts);

        std::string getType() override;
    };
}

#endif