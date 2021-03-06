#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Scene/scene.h"
#include "Entity/Player/player.h"
#include "Entity/Text/text.h"
#include "System/RenderSystem/render_system.h"
#include "System/ControlSystem/control_system.h"
#include "System/CollisionSystem/collision_system.h"
#include "System/MovementSystem/movement_system.h"
#include "System/GameOverSystem/game_over_system.h"
#include "System/PointsBlockSystem/points_block_system.h"
#include "System/TextSystem/text_system.h"
#include "System/WinSystem/win_system.h"
#include "LevelManager/level_manager.h"

namespace Scenes
{
	class GameScene : public Scene
	{
	private:
		Entities::Player * player;
		Entities::Text * score;

		RenderSystem * render_system;
		ControlSystem * control_system;
		CollisionSystem * collision_system;
		MovementSystem * movement_system;
		GameOverSystem * gameover_system;
		PointsBlockSystem * points_block_system;
		TextSystem * text_system;
		WinSystem * win_system;

		LevelManager * level_manager;

	public:
		GameScene();
		~GameScene() override;

		void load() override;
		void unload() override;
	};
}

#endif