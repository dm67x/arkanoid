#include "input_manager.h"

InputManager::InputManager() {
    clear();
    locked = false;
}

InputManager::~InputManager() {
}

void InputManager::addAction(int action, InputManagerFunction callback, bool down) {
    if (down)
        this->down.insert(std::pair<int, InputManagerFunction>(action, callback));
    else
        up.insert(std::pair<int, InputManagerFunction>(action, callback));
}

void InputManager::removeAction(int action, bool down) {
    if (down)
        this->down.erase(action);
    else
        up.erase(action);
}

void InputManager::clear() {
    down.clear();
    up.clear();
}

void InputManager::lock() {
    locked = true;
}

void InputManager::unlock() {
    locked = false;
}
