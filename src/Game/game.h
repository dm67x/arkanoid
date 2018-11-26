#ifndef GAME_H
#define GAME_H

#include "Window/window.h"
#include "EventManager/event_manager.h"
#include "System/RenderSystem/render_system.h"
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
    RenderSystem * render_system;

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
