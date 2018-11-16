/**
 * @file player.h
 * @version 1
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity/Ship/ship.h"

class Player
{

private:
    int _health;
    int _points;
    std::string _name;

    Entities::Ship * _ship;

public:
    Player(std::string name);
    ~Player();

    Entities::Ship * getShip();

};

#endif // PLAYER_H
