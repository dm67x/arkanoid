#include "event_manager.h"

void EventManager::attach(std::string action, EventFunction function) {
	if (listeners.find(action) == listeners.end())
		listeners.insert(std::make_pair(action, function));
}

void EventManager::detach(std::string action) {
	if (listeners.find(action) == listeners.end()) return;
    listeners.erase(action);
}

void EventManager::trigger(std::string action, void * param) {
	if (listeners.find(action) == listeners.end()) return;
    listeners.at(action)(param);
}