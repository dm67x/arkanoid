#include "game.h"
#include "Entity/entity_factory.h"
#include "System/RenderSystem/render_system.h"
#include "System/MovementSystem/movement_system.h"
#include "System/ColliderSystem/collider_system.h"

#include <iostream>

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Echec de l'initialisation de la SDL " <<
            SDL_GetError() << std::endl;
        exit(1);
    }

    window = new Window();
    quit = false;
    entity_factory = Singleton<EntityFactory>::getInstance();
    event_manager = Singleton<EventManager>::getInstance();

    systems.push_back(new RenderSystem(SDL_LoadBMP("./Arkanoid_sprites.bmp")));
    systems.push_back(new MovementSystem());
    systems.push_back(new ColliderSystem());
}

Game::~Game() {
    delete window;

    for (auto s : systems) {
        delete s;
    }

    SDL_Quit();
}

void Game::init() {
    ship = dynamic_cast<Entities::Ship *>(entity_factory->build("ship"));
    ship->setPosition(Vector2<int>(window->getSize().x / 2, window->getSize().y - 20));

    ball = dynamic_cast<Entities::Ball *>(entity_factory->build("ball"));
    ball->setPosition(Vector2<int>(window->getSize().x / 2, window->getSize().y - 40));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            brick = dynamic_cast<Entities::Brick *>(entity_factory->build("brick"));
            brick->setPosition(Vector2<int>(100 + i * 40, 100 + j * 50));
        }
    }

    for (int i = 0; i < window->getSize().x / 31 + 1; i++) {
        brick = dynamic_cast<Entities::Brick *>(entity_factory->build("brick"));
        brick->setPosition(Vector2<int>(15 + i * 31, 0));
        brick->makeInvicible();
        brick = dynamic_cast<Entities::Brick *>(entity_factory->build("brick"));
        brick->setPosition(Vector2<int>(15 + i * 31, window->getSize().y));
        brick->makeInvicible();
    }

    for (int i = 0; i < window->getSize().y / 15 + 1; i++) {
        brick = dynamic_cast<Entities::Brick *>(entity_factory->build("brick"));
        brick->setPosition(Vector2<int>(0, 7 + i * 15));
        brick->makeInvicible();
        brick = dynamic_cast<Entities::Brick *>(entity_factory->build("brick"));
        brick->setPosition(Vector2<int>(window->getSize().x, 7 + i * 15));
        brick->makeInvicible();
    }

    event_manager->attach("quit", [this](void *) {
        this->quit = true;
    });
}

void Game::run() {
    init();

    while (!quit) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                event_manager->trigger("quit", nullptr);
            else if (event.type == SDL_MOUSEBUTTONDOWN)
                event_manager->trigger("launch_ball", nullptr);
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                    event_manager->trigger("quit", nullptr);
            }

            for (auto s : systems) s->input(event);
        }

        for (auto s : systems) s->update(0.0f);

        SDL_FillRect(window->getSurface(), nullptr, 0x000000);

        for (auto s : systems) s->draw(*window->getSurface());

        window->update();
        SDL_Delay(20);
    }
}
