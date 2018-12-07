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
        x = T(0);
        y = T(0);
    }

    /**
     * @brief Vector2 construit un vecteur 2D
     * @param x
     * @param y
     */
    Vector2(T x, T y) {
        this->x = x;
        this->y = y;
    }

    T x, y;

    Vector2 operator*(const Vector2<T> & v) const {
        return Vector2(x * v.x, y * v.y);
    }

    Vector2 operator+(const Vector2<T> & v) const {
        return Vector2(x + v.x, y + v.y);
    }

    Vector2 operator+(const T & d) const {
        return Vector2(x + d, y + d);
    }

    Vector2 operator*(const T & d) const {
        return Vector2(x * d, y * d);
    }

	void normalize() {
		float norm = static_cast<float>(std::sqrt(x * x + y * y));
		x = x / norm;
		y = y / norm;
	}

};

#endif // VECTOR2_H
