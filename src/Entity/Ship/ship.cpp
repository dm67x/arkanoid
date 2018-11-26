#include "ship.h"

using namespace Entities;

Ship::Ship() : DynamicEntity("Ship") {
    setGraphic({ 385, 192, 98, 16 });
}

Ship::~Ship() {
}

std::string Ship::getType() {
    return "ship";
}