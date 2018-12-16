#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Scene/scene.h"
#include "Entity/Player/player.h"
#include "Entity/Brick/brick.h"

namespace Scenes
{
	class GameScene : public Scene
	{
	private:
		Entities::Player * player;
		std::vector<Entities::Brick *> bricks;

	public:
		GameScene();
		~GameScene() override;

		void load() override;
		void unload() override;
	};
}

#endif