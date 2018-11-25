#include "component.h"

Component::Component(std::string name) : name(name) {
}

Component::~Component() {
}

std::string Component::getName() {
    return name;
}