#include "brick.h"
#include "Entity/entity_factory.h"

using namespace Entities;

Brick::Brick() : Brick(50) {
}

Brick::Brick(int points) : Brick(points, 2) {
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
		event_manager->trigger("destroy_entity", this);
        // destroy animation WIP
    }
}

void Brick::makeDestructible() {
    destructible = true;
}

void Brick::makeInvicible() {
    destructible = false;
}

void Entities::Brick::setPoints(int pts)
{
	this->points = pts;
	setGraphicWithPoints();
}

void Brick::setGraphicWithPoints() {
	switch (points) {
	case 50:
		setGraphic({ 0, 0, 30, 14 });
		break;

	case 60:
		setGraphic({ 32, 0, 30, 14 });
		break;

	case 70:
		setGraphic({ 64, 0, 30, 14 });
		break;

	case 80:
		setGraphic({ 96, 0, 30, 14 });
		break;

	case 90:
		setGraphic({ 128, 0, 30, 14 });
		break;

	case 100:
		setGraphic({ 160, 0, 30, 14 });
		break;

	case 110:
		setGraphic({ 0, 16, 30, 14 });
		break;

	case 120:
		setGraphic({ 32, 16, 30, 14 });
		break;

	default:
		setGraphic({ 0, 32, 30, 14 });
		break;
	}
}

std::string Brick::getType() {
    return "brick";
}