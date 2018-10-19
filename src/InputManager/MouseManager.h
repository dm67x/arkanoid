#ifndef MOUSEMANAGER_H
#define MOUSEMANAGER_H

#include "InputManager.h"

class MouseManager : public InputManager
{

public:
    MouseManager();
    ~MouseManager();

    void update(SDL_Event e);

};

#endif // MOUSEMANAGER_H
