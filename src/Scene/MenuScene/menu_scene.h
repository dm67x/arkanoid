#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include "Scene/scene.h"
#include "Entity/Button/button.h"
#include "System/TextSystem/text_system.h"
#include "System/ButtonSystem/button_system.h"

namespace Scenes
{
    class MenuScene : public Scene
    {
    private:
        Entities::Button * play_btn;
        Entities::Button * quit_btn;

        TextSystem * text_system;
        ButtonSystem * button_system;

    public:
        MenuScene();
        ~MenuScene();

        void load() override;
        void unload() override;
    };
}

#endif