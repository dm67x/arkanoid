#include "ball.h"
#include "Component/Components/position.h"
#include "Component/Components/graphic.h"
#include "Component/Components/velocity.h"

using namespace Entities;

Ball::Ball(std::string name) : Entity(name, "ball") {
    SDL_Rect srcBall = { 0, 64, 24, 24 };

    add(std::make_shared<Components::Position>(450, 300));
    add(std::make_shared<Components::Graphic>("./sprites.bmp", srcBall));
    add(std::make_shared<Components::Velocity>(2, 0, -1));
}

Ball::~Ball() {

}
