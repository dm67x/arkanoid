#include "ball.h"
#include "Component/Components/position.h"
#include "Component/Components/graphic.h"

using namespace Entities;

Ball::Ball() : Entity("ball") {
    SDL_Rect srcBall = { 0, 64, 24, 24 };

    add(std::make_shared<Components::Position>(150, 150));
    add(std::make_shared<Components::Graphic>("./sprites.bmp", srcBall));
}

Ball::~Ball() {

}
