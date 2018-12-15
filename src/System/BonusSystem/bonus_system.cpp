#include "bonus_system.h"
#include "Component/bonus.h"
#include "Entity/entity.h"

using namespace Components;

void BonusSystem::update(double deltaTime) {
    if (!current_scene) return;
    EntityManager * manager = current_scene->getEntityManager();
    for (auto entity : manager->get()) {
        Bonus * bonus = entity->get<Bonus>("bonus");
        if (!bonus) continue;
    }
}