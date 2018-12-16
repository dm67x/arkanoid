#include <iostream>
#include <cassert>

#include "game_scene.h"
#include "Component/transform.h"
#include "Component/motion.h"
#include "Component/ball_number.h"
#include "Level/level.h"
#include "System/system_manager.h"

using namespace Scenes;

GameScene::GameScene() : Scene("game") {
	SDL_Surface * sprite = SDL_LoadBMP("./assets/Arkanoid_sprites.bmp");
	SDL_Surface * font = SDL_LoadBMP("./assets/Arkanoid_ascii.bmp");

	if (!sprite || !font) {
		std::cerr << "error on reading assets files" << std::endl;
		exit(1);
	}

	render_system = new RenderSystem(*sprite);
	control_system = new ControlSystem();
	collision_system = new CollisionSystem();
	movement_system = new MovementSystem();
	gameover_system = new GameOverSystem();
	points_block_system = new PointsBlockSystem();
	text_system = new TextSystem(*font);
	win_system = new WinSystem();

	system_manager->add("gamescene_render", *render_system);
	system_manager->add("gamescene_control", *control_system);
	system_manager->add("gamescene_collision", *collision_system);
	system_manager->add("gamescene_movement", *movement_system);
	system_manager->add("gamescene_gameover", *gameover_system);
	system_manager->add("gamescene_pointsblock", *points_block_system);
	system_manager->add("gamescene_text", *text_system);
	system_manager->add("gamescene_win", *win_system);

	level_manager = Singleton<LevelManager>::getInstance();
	level_manager->add(new Level("./assets/levels/level2.txt"));
	
	player = new Entities::Player("Joueur 1");

	score = new Entities::Text(std::to_string(player->getScore()));
	Components::Transform * score_tc = score->get<Components::Transform>("transform");
	score_tc->position = Vector2<float>(10, 10);
	score_tc->scale = Vector2<float>(0.5f, 0.5f);

	event_manager->attach("remove_ball_from_player", [this](void * param) {
		if (!player) return;
		Components::BallNumber * number = player->get<Components::BallNumber>("ball_number");
		if (number) {
			number->number -= 1;
		}
	});

	event_manager->attach("add_points", [this](void * param) {
		int points = *(static_cast<int *>(param));
		if (!player) return;
		player->addScore(points);
		score->setText(std::to_string(player->getScore()));
	});
}

GameScene::~GameScene() {
	event_manager->detach("remove_ball_from_player");
	event_manager->detach("add_points");

	system_manager->remove("gamescene_render");
	system_manager->remove("gamescene_control");
	system_manager->remove("gamescene_collision");
	system_manager->remove("gamescene_movement");
	system_manager->remove("gamescene_gameover");
	system_manager->remove("gamescene_pointsblock");
	system_manager->remove("gamescene_text");
	system_manager->remove("gamescene_win");
}

void GameScene::load() {
	render_system->setActive(true);
	control_system->setActive(true);
	collision_system->setActive(true);
	movement_system->setActive(true);
	gameover_system->setActive(true);
	points_block_system->setActive(true);
	text_system->setActive(true);

	player->setPosition(Vector2<float>(getWidth() / 2, getHeight() - 20.0f));
	player->setActive(true);
	score->setActive(true);
	level_manager->get()->load();
}

void GameScene::unload() {
	player->setActive(false);
	score->setActive(false);
	render_system->setActive(false);
	control_system->setActive(false);
	collision_system->setActive(false);
	movement_system->setActive(false);
	gameover_system->setActive(false);
	points_block_system->setActive(false);
	text_system->setActive(false);
	level_manager->get()->unload();
}
