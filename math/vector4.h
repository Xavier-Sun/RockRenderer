#ifndef VECTOR_4_H
#define VECTOR_4_H

#include <cmath>

class Vector4
{
    float x;
    float y;
    float z;
    float w;

public:
    float get_x() const { return x; }
    float get_y() const { return y; }
    float get_z() const { return z; }
    float get_w() const { return w; }

    void set_x(float value) { x = value; }
    void set_y(float value) { y = value; }
    void set_z(float value) { z = value; }
    void set_w(float value) { w = value; }

    Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

    Vector4(float p_x, float p_y, float p_z, float p_w) : x(p_x), y(p_y), z(p_z), w(p_w) {}

    ~Vector4() {}
};

inline const Vector4 operator+(const Vector4 &lhs, const Vector4 &rhs)
{
    return Vector4(lhs.get_x() + rhs.get_x(),
                   lhs.get_y() + rhs.get_y(),
                   lhs.get_z() + rhs.get_z(),
                   lhs.get_w() + rhs.get_w());
}

inline const Vector4 operator-(const Vector4 &lhs, const Vector4 &rhs)
{
    return Vector4(lhs.get_x() - rhs.get_x(),
                   lhs.get_y() - rhs.get_y(),
                   lhs.get_z() - rhs.get_z(),
                   lhs.get_w() - rhs.get_w());
}

inline const float dot(const Vector4 &lhs, const Vector4 &rhs)
{
    return lhs.get_x() * rhs.get_x() +
           lhs.get_y() * rhs.get_y() +
           lhs.get_z() * rhs.get_z() +
           lhs.get_w() * rhs.get_w();
}

inline const Vector4 operator*(const Vector4 &lhs, float rhs)
{
    return Vector4(lhs.get_x() * rhs,
                   lhs.get_y() * rhs,
                   lhs.get_y() * rhs,
                   lhs.get_w() * rhs);
}

inline const Vector4 operator/(const Vector4 &lhs, float rhs)
{
    return Vector4(lhs.get_x() / rhs,
                   lhs.get_y() / rhs,
                   lhs.get_y() / rhs,
                   lhs.get_w() / rhs);
}

inline const float magnitude(const Vector4 &v)
{
    return sqrt(dot(v, v));
}

inline const Vector4 normalize(const Vector4 &v)
{
    return v / magnitude(v);
}

#endif
