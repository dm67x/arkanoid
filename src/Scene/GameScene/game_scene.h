#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Scene/scene.h"
#include "Entity/Player/player.h"

namespace Scenes
{
	class GameScene : public Scene
	{
	private:
		Entities::Player * player;

	public:
		GameScene();
		~GameScene() override;

		void load() override;
	};
}

#endif