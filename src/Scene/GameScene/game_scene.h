#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Scene/scene.h"

namespace Scenes
{
	class GameScene : public Scene
	{
	public:
		GameScene();
		~GameScene() override;

		void load() override;
		void update(float deltaTime) override;
		void draw(SDL_Surface & surface) override;
		void input(SDL_Event e) override;
	};
}

#endif