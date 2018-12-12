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
	};
}

#endif