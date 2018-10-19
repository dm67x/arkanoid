#include "InputManager.h"

InputManager::InputManager() {
    clear();
    _locked = false;
}

InputManager::~InputManager() {
}

void InputManager::addAction(int action, InputManagerFunction callback, bool down) {
    if (down)
        _down.insert(std::pair<int, InputManagerFunction>(action, callback));
    else
        _up.insert(std::pair<int, InputManagerFunction>(action, callback));
}

void InputManager::removeAction(int action, bool down) {
    if (down)
        _down.erase(action);
    else
        _up.erase(action);
}

void InputManager::clear() {
    _down.clear();
    _up.clear();
}

void InputManager::lock() {
    _locked = true;
}

void InputManager::unlock() {
    _locked = false;
}
