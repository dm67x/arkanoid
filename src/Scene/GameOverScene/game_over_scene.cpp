#include "game_over_scene.h"
#include "System/TextSystem/text_system.h"
#include "Component/transform.h"
#include <iostream>

using namespace Scenes;

GameOverScene::GameOverScene() : Scene("game_over") {
    game_over_text = new Entities::Text("Game Over");

    SDL_Surface * font = SDL_LoadBMP("./assets/Arkanoid_ascii.bmp");

	if (!font) {
		std::cerr << "error on reading assets files" << std::endl;
		exit(1);
	}

	systems.push_back(new TextSystem(*font));
}

GameOverScene::~GameOverScene() {
    delete game_over_text;
}

void GameOverScene::load() {
    game_over_text->get<Components::Transform>("transform")->position =
        Vector2<float>(getWidth() / 2, getHeight() / 2);

    game_over_text->setActive(true);
}

void GameOverScene::unload() {
    game_over_text->setActive(false);
}