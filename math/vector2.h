#ifndef VECTOR_2_H
#define VECTOR_2_H

#include <cmath>

class Vector2
{
    float x;
    float y;

public:
    float get_x() const { return x; }
    float get_y() const { return y; }

    void set_x(float value) { x = value; }
    void set_y(float value) { y = value; }

    Vector2() : x(0.0f), y(0.0f) {}

    Vector2(float p_x, float p_y) : x(p_x), y(p_y) {}

    ~Vector2() {}
};

inline const Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs)
{
    return Vector2(lhs.get_x() + rhs.get_x(),
                   lhs.get_y() + rhs.get_y());
}

inline const Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs)
{
    return Vector2(lhs.get_x() - rhs.get_x(),
                   lhs.get_y() - rhs.get_y());
}

inline const float dot(const Vector2 &lhs, const Vector2 &rhs)
{
    return lhs.get_x() * rhs.get_x() +
           lhs.get_y() * rhs.get_y();
}

inline const Vector2 operator*(const Vector2 &lhs, float rhs)
{
    return Vector2(lhs.get_x() * rhs,
                   lhs.get_y() * rhs);
}

inline const Vector2 operator/(const Vector2 &lhs, float rhs)
{
    return Vector2(lhs.get_x() / rhs,
                   lhs.get_y() / rhs);
}

inline const float magnitude(const Vector2 &v)
{
    return sqrt(dot(v, v));
}

inline const Vector2 normalize(const Vector2 &v)
{
    return v / magnitude(v);
}

inline const float distance(const Vector2 &lhs, const Vector2 &rhs)
{
    return magnitude(lhs - rhs);
}

#endif
