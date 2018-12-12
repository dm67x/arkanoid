#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component
{
public:
	virtual std::string name() const = 0;
};

#endif