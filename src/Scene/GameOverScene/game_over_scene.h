#ifndef GAME_OVER_SCENE_H
#define GAME_OVER_SCENE_H

#include "Scene/scene.h"

namespace Scenes
{
    class GameOverScene : public Scene
    {
    private:
        SDL_Surface * game_over_img;

    public:
        GameOverScene();
        ~GameOverScene();

        void load() override;
        void unload() override;
        void draw(SDL_Surface & surface) override;
    };
}

#endif