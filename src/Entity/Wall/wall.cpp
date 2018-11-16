/**
 * @file wall.cpp
 * @version 1
 */

#include "wall.h"

using namespace Entities;

Wall::Wall() : Entity("wall") {
	_src_rect = { 0, 0, 31, 15 };
}

Wall::~Wall() {
}

void Wall::hit() {
    _hit--;
}

void Wall::setHit(int hit) {
    _hit = hit;
}

void Wall::setPoints(int points) {
    _points = points;
}

void Wall::destroyable() {
    _can_be_destroyed = true;
}

void Wall::indestructible() {
    _can_be_destroyed = false;
}

void Wall::setBonus(PowerUp & power) {
    _bonus = &power;
}

int Wall::getHit() {
    return _hit;
}

int Wall::getPoints() {
    return _points;
}

bool Wall::isDestroyable() {
    return _can_be_destroyed;
}

PowerUp * Wall::getBonus() {
    return _bonus;
}
