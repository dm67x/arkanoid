#include "game_over_scene.h"
#include "Component/transform.h"
#include "System/system_manager.h"
#include <iostream>

using namespace Scenes;

GameOverScene::GameOverScene() : Scene("game_over") {
    SDL_Surface * font = SDL_LoadBMP("./assets/Arkanoid_ascii.bmp");

	if (!font) {
		std::cerr << "error on reading assets files" << std::endl;
		exit(1);
	}

    text_system = new TextSystem(*font);

    system_manager->add("gameover_text", *text_system);

    game_over_text = new Entities::Text("Game Over");
}

GameOverScene::~GameOverScene() {
    delete game_over_text;
    system_manager->remove("gameover_text");
}

void GameOverScene::load() {
    text_system->setActive(true);

    game_over_text->get<Components::Transform>("transform")->position =
        Vector2<float>(getWidth() / 2, getHeight() / 2);

    game_over_text->setActive(true);
}

void GameOverScene::unload() {
    text_system->setActive(false);
    game_over_text->setActive(false);
}