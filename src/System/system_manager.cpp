#include "system_manager.h"

void SystemManager::add(std::string name, System & s) {
    systems.insert(std::make_pair(name, &s));
}

void SystemManager::remove(std::string name) {
    try {
        System * s = systems.at(name);
        delete s;
        systems.erase(name);
    } catch (std::out_of_range) {
    }
}

std::vector<System *> SystemManager::get() {
    std::vector<System *> sys;
    for (auto s : systems) {
        if (s.second->isActive())
            sys.push_back(s.second);
    }
    return sys;
}