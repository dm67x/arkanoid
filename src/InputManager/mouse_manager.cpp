#include "mouse_manager.h"

MouseManager::MouseManager() : InputManager() {

}

MouseManager::~MouseManager() {

}

void MouseManager::update(SDL_Event e) {
    if (locked) return;

    if (e.type == SDL_MOUSEBUTTONDOWN) {
        for (auto pair : down) {
            if (e.button.button == pair.first)
                pair.second(e);
        }
    } else if (e.type == SDL_MOUSEBUTTONUP) {
        for (auto pair : up) {
            if (e.button.button == pair.first)
                pair.second(e);
        }
    }
}
