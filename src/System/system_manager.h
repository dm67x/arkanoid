#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "system.h"
#include "singleton.h"
#include <map>
#include <vector>
#include <string>

class SystemManager : public Singleton<SystemManager>
{
private:
    std::map<std::string, System *> systems;

public:
    void add(std::string name, System & s);
    void remove(std::string name);
    std::vector<System *> get();
};

#endif