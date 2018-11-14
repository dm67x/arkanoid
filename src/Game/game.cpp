#include "game.h"
#include "InputManager/key_manager.h"
#include "InputManager/mouse_manager.h"
#include "Entity/Entities/ball.h"
#include "Entity/Entities/ship.h"
#include "Component/Components/position.h"

#include <iostream>

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Echec de l'initialisation de la SDL " <<
            SDL_GetError() << std::endl;
        exit(1);
    }

    window = new Window();
    quit = false;
    keyManager = new KeyManager();
    mouseManager = new MouseManager();
    entity_factory = Singleton<EntityFactory>::getInstance();
    renderer = new Systems::Render();
    movement = new Systems::Movement();
}

Game::~Game() {
    delete window;
    delete keyManager;
    delete mouseManager;
    delete renderer;
    delete movement;
    SDL_Quit();
}

void Game::init() {
    keyManager->addAction(SDLK_ESCAPE, [this](SDL_Event) {
        this->quit = true;
    });

    mouseManager->addAction(SDL_BUTTON_LEFT, [](SDL_Event e) {
        std::cout << "mouse click, X: " << e.button.x << ", Y: " << e.button.y << std::endl;
    });

    entity_factory->create("ball_1", "ball");
    entity_factory->create("ship_1", "ship");
}

void Game::update() {
    movement->update(0);
}

void Game::draw() {
    renderer->draw(*window->getSurface());
}

void Game::run() {
    init();

    while (!quit) {
        if (SDL_PollEvent(&event)) {
            keyManager->update(event);
            mouseManager->update(event);

            if (event.type == SDL_QUIT)
                quit = true;
        }

        update();
        SDL_FillRect(window->getSurface(), NULL, 0x000000);
        draw();

        window->update();
        SDL_Delay(20);
    }
}
