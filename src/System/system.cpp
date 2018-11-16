#include "system.h"

EntityFactory * System::_entity_factory = Singleton<EntityFactory>::getInstance();

System::System() {
}

System::~System() {
}