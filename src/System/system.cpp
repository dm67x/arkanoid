#include "system.h"

EntityPool * System::pool = Singleton<EntityPool>::getInstance();
EventManager * System::event_manager = Singleton<EventManager>::getInstance();