#include "ball.h"

using namespace Entities;

Ball::Ball() : DynamicEntity("ball") {
    setGraphic({ 80, 64, 16, 16 });
    setDirection(Vector2<int>(0, 1));
    setSpeed(5.0f);
}

Ball::~Ball() {
}

std::string Ball::getType() {
    return "ball";
}