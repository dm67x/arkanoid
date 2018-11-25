#include "game.h"
#include "InputManager/key_manager.h"
#include "InputManager/mouse_manager.h"
#include "Component/transform.h"
#include "Component/graphic.h"

#include <iostream>

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Echec de l'initialisation de la SDL " <<
            SDL_GetError() << std::endl;
        exit(1);
    }

    window = new Window();
    quit = false;
    key_manager = new KeyManager();
    mouse_manager = new MouseManager();
    render_system = new RenderSystem();
}

Game::~Game() {
    delete window;
    delete key_manager;
    delete mouse_manager;
    delete render_system;

    SDL_Quit();
}

void Game::init() {
    key_manager->addAction(SDLK_ESCAPE, [this](SDL_Event) {
        this->quit = true;
    });

    mouse_manager->addAction(SDL_BUTTON_LEFT, [](SDL_Event e) {
        std::cout << "mouse click, X: " << e.button.x << ", Y: " << e.button.y << std::endl;
    });

    Entity ship("ship");
    Components::Transform transform;
    transform.position = Vector2<int>(150, 150);
    ship.add(&transform);
    Components::Graphic graphic;
    graphic.graphic = { 385, 192, 98, 16 };
    ship.add(&graphic);
}

void Game::run() {
    init();

    while (!quit) {
        if (SDL_PollEvent(&event)) {
            key_manager->update(event);
            mouse_manager->update(event);

            if (event.type == SDL_QUIT)
                quit = true;
        }

        SDL_FillRect(window->getSurface(), nullptr, 0x000000);
        render_system->draw(*window->getSurface());
        window->update();
        SDL_Delay(20);
    }
}
