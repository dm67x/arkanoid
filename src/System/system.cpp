#include "system.h"

EntityPool * System::entity_pool = Singleton<EntityPool>::getInstance();

System::System() {
}

System::~System() {

}
