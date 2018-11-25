/**
 * @file wall.cpp
 * @version 1
 */

#include "wall.h"
#include "Component/Graphic/graphic.h"
#include "Component/Position/position.h"

using namespace Entities;

Wall::Wall() : Entity("wall") {
	addComponent(new Components::Graphic({ 0, 0, 31, 15 }));
    addComponent(new Components::Position());
	_bonus = nullptr;
}

Wall::~Wall() {
}

void Wall::setBonus(PowerUp & power) {
    _bonus = &power;
}

PowerUp * Wall::getBonus() {
    return _bonus;
}
