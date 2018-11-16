/**
 * @file player.cpp
 * @version 1
 */

#include "player.h"
#include "Entity/entity_factory.h"

Player::Player(std::string name) : _name(name) {
    EntityFactory * factory = Singleton<EntityFactory>::getInstance();
    _ship = dynamic_cast<Entities::Ship*>(factory->create("ship"));
}

Player::~Player() {
    delete _ship;
}

Entities::Ship * Player::getShip() {
    return _ship;
}
