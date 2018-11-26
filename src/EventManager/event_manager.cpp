#include "event_manager.h"

void EventManager::attach(std::string action, EventFunction function) {
    listeners.insert(std::make_pair(action, function));
}

void EventManager::detach(std::string action) {
    listeners.erase(action);
}

void EventManager::trigger(std::string action, void * param) {
    listeners.at(action)(param);
}