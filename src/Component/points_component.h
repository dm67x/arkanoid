#ifndef POINTS_COMPONENT_H
#define POINTS_COMPONENT_H

#include "component.h"

class PointsComponent : public Component
{
public:
	PointsComponent(Entity id, int pts) : Component(id), points(pts) {}
	PointsComponent(Entity id) : PointsComponent(id, 50) {}

	int points;

	std::string getName() override { return "points"; }
};

#endif