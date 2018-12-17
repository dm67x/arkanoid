#include "win_system.h"
#include "Component/health.h"
#include "LevelManager/level_manager.h"
#include "Scene/scene_manager.h"

void WinSystem::update(double deltaTime) {
    System::update(deltaTime);

    bool exist = false;
    for (auto entity : entity_manager->get()) {
        if (entity->get<Components::Health>("health")) {
			exist = true;
			break;
		}
    }
    
    //SDL_Log("%d\n", exist);

    if (!exist) {
        // Passer au niveau suivant sinon terminer jeu
        bool res = Singleton<LevelManager>::getInstance()->next();
        if (!res) {
            Singleton<SceneManager>::getInstance()->load("gameover");
        }
    }
}
