#ifndef GAME_OVER_SCENE_H
#define GAME_OVER_SCENE_H

#include "Scene/scene.h"
#include "Entity/Text/text.h"
#include "System/TextSystem/text_system.h"

namespace Scenes
{
    class GameOverScene : public Scene
    {
    private:
        Entities::Text * game_over_text;
        TextSystem * text_system;

    public:
        GameOverScene();
        ~GameOverScene();

        void load() override;
        void unload() override;
    };
}

#endif