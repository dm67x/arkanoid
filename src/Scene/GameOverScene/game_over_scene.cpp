#include "game_over_scene.h"
#include <iostream>

using namespace Scenes;

GameOverScene::GameOverScene() : Scene("game_over") {
    game_over_img = SDL_LoadBMP("./assets/gameover.bmp");
}

GameOverScene::~GameOverScene() {
}

void GameOverScene::load() {
}

void GameOverScene::unload() {
}

void GameOverScene::draw(SDL_Surface & surface) {
    SDL_FillRect(&surface, nullptr, 0x000000);
    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    dest.w = getWidth();
    dest.h = getHeight();
    SDL_BlitScaled(game_over_img, nullptr, &surface, &dest);
}