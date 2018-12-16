#include "menu_scene.h"
#include "Component/transform.h"
#include "Component/text.h"
#include "Scene/scene_manager.h"
#include "System/system_manager.h"
#include <iostream>

using namespace Scenes;

MenuScene::MenuScene() : Scene("menu") {
    SDL_Surface * font = SDL_LoadBMP("./assets/Arkanoid_ascii.bmp");

	if (!font) {
		std::cerr << "error on reading assets files" << std::endl;
		exit(1);
	}

    text_system = new TextSystem(*font);
    button_system = new ButtonSystem();

    system_manager->add("menu_text", *text_system);
    system_manager->add("menu_button", *button_system);

    play_btn = new Entities::Button("Jouer", "play_btn_action");
    quit_btn = new Entities::Button("Quitter", "quit_btn_action");

    event_manager->attach("play_btn_action", [](void * p) {
        Singleton<SceneManager>::getInstance()->load("game");
    });

    event_manager->attach("quit_btn_action", [](void * p) {
        exit(0);
    });
}

MenuScene::~MenuScene() {
    delete play_btn;
    delete quit_btn;
    event_manager->detach("play_btn_action");
    event_manager->detach("quit_btn_action");

    system_manager->remove("menu_text");
    system_manager->remove("menu_button");
}

void MenuScene::load() {
    text_system->setActive(true);
    button_system->setActive(true);

    play_btn->setActive(true);
    quit_btn->setActive(true);

    Components::Text * tc = play_btn->get<Components::Text>("text");
    Components::Sprite * sp = tc->sprites[0];
    Components::Transform * trc = play_btn->get<Components::Transform>("transform");

    int tw = sp->src.w * trc->scale.x * tc->sprites.size();
    int th = sp->src.h * trc->scale.y;

    trc->position.x = (getWidth() - tw) * 0.5f;
    trc->position.y = (getHeight() - th) * 0.5f - getHeight() / 4.0f;

    tc = quit_btn->get<Components::Text>("text");
    sp = tc->sprites[0];
    trc = quit_btn->get<Components::Transform>("transform");
    
    tw = sp->src.w * trc->scale.x * tc->sprites.size();
    th = sp->src.h * trc->scale.y;

    trc->position.x = (getWidth() - tw) * 0.5f;
    trc->position.y = (getHeight() - th) * 0.5f + getHeight() / 4.0f;
}

void MenuScene::unload() {
    text_system->setActive(false);
    button_system->setActive(false);
    play_btn->setActive(false);
    quit_btn->setActive(false);
}