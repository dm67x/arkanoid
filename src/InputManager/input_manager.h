#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <map>
#include <SDL.h>
#include <functional>

using InputManagerFunction = std::function<void(SDL_Event)>;

class InputManager
{

protected:
    std::map<int, InputManagerFunction> up, down;
    bool locked;

public:
    InputManager();
    virtual ~InputManager();

    void addAction(int action, InputManagerFunction callback, bool down = true);
    void removeAction(int action, bool down = true);
    void clear();
    void lock();
    void unlock();

    virtual void update(SDL_Event e) = 0;

};

#endif // INPUT_MANAGER_H
