#include "ship.h"
#include "Component/Components/position.h"
#include "Component/Components/graphic.h"
#include "Component/Components/velocity.h"

using namespace Entities;

Ship::Ship(std::string name) : Entity(name, "ship") {
    SDL_Rect scrVaiss = { 128, 0, 128, 32 };

    add(std::make_shared<Components::Position>(150, 700));
    add(std::make_shared<Components::Graphic>("./sprites.bmp", scrVaiss));
    add(std::make_shared<Components::Velocity>(2, 1, 0));
}

Ship::~Ship() {
    // delete des composants
}
