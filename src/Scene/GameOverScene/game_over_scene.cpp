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

    Components::Text * tc = game_over_text->get<Components::Text>("text");
    Components::Sprite * sp = tc->sprites[0];
    if (!sp) return;
    Components::Transform * trc = game_over_text->get<Components::Transform>("transform");
    int tw = sp->src.w * trc->scale.x * tc->sprites.size();
    int th = sp->src.h * trc->scale.y;

    trc->position.x = (getWidth() - tw) * 0.5f;
    trc->position.y = (getHeight() - th) * 0.5f;

    game_over_text->setActive(true);
}

void GameOverScene::unload() {
    text_system->setActive(false);
    game_over_text->setActive(false);
}