/**
 * @file ship.cpp
 * @version 1
 */

#include "ship.h"

using namespace Entities;

Ship::Ship() : Entity("ship") {
    setPosition(Vector2<int>(100, 500));
    _src_rect = { 385, 192, 98, 16 };
}

Ship::~Ship() {
}
