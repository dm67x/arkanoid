#include "ship.h"

using namespace Entities;

Ship::Ship() : DynamicEntity("Ship") {
    setGraphic({ 385, 192, 98, 16 });
    setSpeed(0.0f);

    event_manager->attach("move_ship", [this](void * p) {
        SDL_Event * e = (SDL_Event *)p;
        this->setPosition(Vector2<int>(e->motion.x, this->getPosition().y));
    });
}

Ship::~Ship() {
}

std::string Ship::getType() {
    return "ship";
}