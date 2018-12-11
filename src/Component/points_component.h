#ifndef POINTS_COMPONENT_H
#define POINTS_COMPONENT_H

#include "component.h"

class PointsComponent : public Component
{
public:
	PointsComponent(int pts) : Component(), points(pts) {}
	PointsComponent() : PointsComponent(50) {}

	int points;

	std::string getName() override { return "points"; }
};

#endif