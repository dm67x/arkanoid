#ifndef GAME_H
#define GAME_H

#include "Window/window.h"
#include "InputManager/input_manager.h"
#include "Entity/entity_factory.h"
#include "System/Systems/render.h"
#include "System/Systems/movement.h"

class Game
{

private:
    Window * window;
    bool quit;
    SDL_Event event;
    InputManager * keyManager, * mouseManager;

    EntityFactory * entity_factory;
    Systems::Render * renderer;
    Systems::Movement * movement;

protected:
    void init();
    void update();
    void draw();

public:
    Game();
    ~Game();

    void run();

};

#endif // GAME_H
