#include "bonus_system.h"
#include "Component/bonus.h"
#include "Entity/entity.h"

using namespace Components;

void BonusSystem::update(double deltaTime) {
    System::update(deltaTime);

    EntityManager * manager = current->getManager();
    for (auto entity : manager->get()) {
        Bonus * bonus = entity->get<Bonus>("bonus");
        if (!bonus) continue;
    }
}