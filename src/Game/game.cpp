#include "game.h"
#include "Entity/entity_factory.h"

#include <iostream>

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Echec de l'initialisation de la SDL " <<
            SDL_GetError() << std::endl;
        exit(1);
    }

    window = new Window();
    quit = false;
    render_system = new RenderSystem(SDL_LoadBMP("./Arkanoid_sprites.bmp"));
    entity_factory = Singleton<EntityFactory>::getInstance();
    event_manager = Singleton<EventManager>::getInstance();
}

Game::~Game() {
    delete window;
    delete render_system;

    SDL_Quit();
}

void Game::init() {
    ship = dynamic_cast<Entities::Ship *>(entity_factory->build("ship"));
    ship->setPosition(Vector2<int>(window->getSize().x / 2, window->getSize().y - 20));

    ball = dynamic_cast<Entities::Ball *>(entity_factory->build("ball"));
    ball->setPosition(Vector2<int>(window->getSize().x / 2, window->getSize().y -40));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            brick = dynamic_cast<Entities::Brick *>(entity_factory->build("brick"));
            brick->setPosition(Vector2<int>(100 + i * 40, 100 + j * 50));
        }
    }

    event_manager->attach("quit", [this](void *) {
        this->quit = true;
    });

    event_manager->attach("showMouseInfo", [](void * e) {
        SDL_Event * ev = static_cast<SDL_Event *>(e);
        std::cout << "mouse click, X: " << ev->button.x << ", Y: " << ev->button.y << std::endl;
    });

    event_manager->attach("moveShip", [this](void * e) {
        SDL_Event * ev = static_cast<SDL_Event *>(e);
        this->ship->setPosition(Vector2<int>(ev->motion.x, ship->getPosition().y));
    });
}

void Game::run() {
    init();

    while (!quit) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                event_manager->trigger("quit", nullptr);
            else if (event.type == SDL_MOUSEBUTTONDOWN)
                event_manager->trigger("showMouseInfo", &event);
            else if (event.type == SDL_MOUSEMOTION)
                event_manager->trigger("moveShip", &event);
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                    event_manager->trigger("quit", nullptr);
            }
        }

        SDL_FillRect(window->getSurface(), nullptr, 0x000000);
        render_system->draw(*window->getSurface());
        window->update();
        SDL_Delay(20);
    }
}
