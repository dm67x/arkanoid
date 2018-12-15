#ifndef BOARD_H
#define BOARD_H

#include "vector2.h"
#include "Window/window.h"

class Board
{
private:
    Vector2<int> size;
    Window * window;
    Vector2<float> brick_size;

public:
    Board(int line, int column);

    const Vector2<float> getBrickScale();
    Vector2<float> getPosition(int line, int column);
};

#endif