#include "board.h"

Board::Board(int line, int column) {
    size.y = line;
    size.x = column;
    window = Singleton<Window>::getInstance();
}

const Vector2<float> Board::getBrickScale() {
    float bw = 30.0f, bh = 14.0f;
    int ww = window->getSize().x, wh = window->getSize().y;
    return Vector2<float>((ww / static_cast<float>(size.x)) / bw, 
        (wh / static_cast<float>(size.y)) / bh);
}

Vector2<float> Board::getPosition(int line, int column) {
    float bw = 30.0f, bh = 14.0f;
    Vector2<float> scale = getBrickScale();
    return Vector2<float>(column * bw * scale.x + bw * scale.x * 0.5f, 
        line * bh * scale.y + bh * scale.y * 0.5f);
}