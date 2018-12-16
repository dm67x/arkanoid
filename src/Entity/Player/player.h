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
        int score;

    public:
        Player(const std::string name);
        ~Player() override;

        void setActive(bool active) override;
        void setPosition(Vector2<float> position);
        void addScore(int points);
        void resetScore();
        inline const int getScore() { return score; }
    };
}

#endif