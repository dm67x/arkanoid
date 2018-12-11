#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component
{
protected:
	Component() {}

public:
	virtual std::string getName() = 0;
};

#endif