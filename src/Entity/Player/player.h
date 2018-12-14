#ifndef PLAYER_H
#define PLAYER_H

#include "Entity/Ball/ball.h"
#include "Entity/Ship/ship.h"
#include "vector2.h"
#include <vector>

namespace Entities
{
    class Player : public Entity
    {
    private:
        Entities::Ship * ship;
        std::vector<Entities::Ball *> balls;
        std::string name;

    public:
        Player(const std::string name, Vector2<float> position, EntityManager * manager);
        ~Player() override;
    };
}

#endif