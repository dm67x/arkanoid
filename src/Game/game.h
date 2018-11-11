#ifndef GAME_H
#define GAME_H

#include "Window/Window.h"
#include "InputManager/input_manager.h"
#include "Entity/entity_factory.h"
#include "System/Systems/render.h"

class Game
{

private:
    Window * window;
    bool quit;
    SDL_Event event;
    InputManager * keyManager, * mouseManager;

    EntityFactory * entity_factory;
    Systems::Render * renderer;

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
