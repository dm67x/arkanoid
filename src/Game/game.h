#ifndef GAME_H
#define GAME_H

#include "Window/window.h"
#include "EventManager/event_manager.h"
#include "System/system.h"
#include "Entity/entity_factory.h"
#include "Entity/Ship/ship.h"
#include "Entity/Brick/brick.h"
#include "Entity/Ball/ball.h"

class Game
{

private:
    Window * window;
    bool quit;
    SDL_Event event;
    EventManager * event_manager;
    EntityFactory * entity_factory;

    // Systems
    std::vector<System *> systems;

    // Test
    Entities::Ship * ship;
    Entities::Brick * brick;
    Entities::Ball * ball;

protected:
    void init();

public:
    Game();
    ~Game();

    void run();

};

#endif // GAME_H
