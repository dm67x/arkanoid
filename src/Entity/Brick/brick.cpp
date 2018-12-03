#include "brick.h"
#include "Entity/entity_factory.h"

using namespace Entities;

Brick::Brick(int points) : Brick(points, 1) {
}

Brick::Brick(int points, int hit) : StaticEntity("Brick") {
    this->hit = hit;
	this->points = points;
    makeDestructible();
	setGraphicWithPoints();
}

Brick::~Brick() {
}

void Brick::setHit(int hit) {
    this->hit = hit;
}

void Brick::damage(int force) {
    if (!destructible) return;
    hit -= force;
    if (hit <= 0) {
        Singleton<EntityFactory>::getInstance()->destroy(this); // destroy animation WIP
    }
}

void Brick::makeDestructible() {
    destructible = true;
}

void Brick::makeInvicible() {
    destructible = false;
}

void Brick::setGraphicWithPoints() {
	setGraphic({ 0, 0, 31, 15 });
	/*if (points <= 50) {

	}*/
}

std::string Brick::getType() {
    return "brick";
}