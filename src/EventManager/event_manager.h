#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <map>
#include <functional>
#include "singleton.h"

using EventFunction = std::function<void(void *)>;

class EventManager : public Singleton<EventManager>
{
private:
    std::map<std::string, EventFunction> listeners;

public:
    void attach(std::string action, EventFunction function);
    void detach(std::string action);
    void trigger(std::string action, void * param);
};

#endif
