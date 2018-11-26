#include "ball.h"

using namespace Entities;

Ball::Ball() : DynamicEntity("ball") {
    setGraphic({ 80, 64, 16, 16 });
}

Ball::~Ball() {
}

std::string Ball::getType() {
    return "ball";
}