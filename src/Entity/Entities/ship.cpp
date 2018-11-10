#include "ship.h"
#include "Component/Components/position.h"
#include "Component/Components/graphic.h"

using namespace Entities;

Ship::Ship() : Entity("ship") {
    SDL_Rect scrVaiss = { 128, 0, 128, 32 };

    add(std::make_shared<Components::Position>(150, 150));
    add(std::make_shared<Components::Graphic>("./sprites.bmp", scrVaiss));
}

Ship::~Ship() {

}
