/**
 * @file ship.cpp
 * @version 1
 */

#include "ship.h"
#include "Component/Graphic/graphic.h"
#include "Component/Position/position.h"

using namespace Entities;

Ship::Ship() : Entity("ship") {
    addComponent(new Components::Graphic({ 385, 192, 98, 16 }));
    addComponent(new Components::Position());
}

Ship::~Ship() {
}
