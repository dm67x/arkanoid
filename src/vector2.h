#ifndef VECTOR2_H
#define VECTOR2_H

/**
 * @brief Vector2 classe permettant d'initialiser un vecteur 2D
 */
template<typename T>
class Vector2
{

public:
    /**
     * @brief Vector2
     */
    Vector2() {
        _x = T(0);
        _y = T(0);
    }

    /**
     * @brief Vector2 construit un vecteur 2D
     * @param x
     * @param y
     */
    Vector2(T x, T y) {
        this->_x = x;
        this->_y = y;
    }

    T _x, _y;

    Vector2<T> operator*(Vector2<T> & v) {
        return Vector2<T>(_x * v._x, _y * v._y);
    }

    Vector2<T> operator+(Vector2<T> & v) {
        return Vector2<T>(_x + v._x, _y + v._y);
    }

    Vector2<T> operator+(T d) {
        return Vector2<T>(_x + d, _y + d);
    }

    Vector2<T> operator*(T d) {
        return Vector2<T>(_x * d, _y * d);
    }

};

#endif // VECTOR2_H
