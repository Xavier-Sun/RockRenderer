#ifndef VECTOR_3_H
#define VECTOR_3_H

#include <cmath>

class Vector3
{
    float x;
    float y;
    float z;

public:
    float get_x() const { return x; }
    float get_y() const { return y; }
    float get_z() const { return z; }

    void set_x(float value) { x = value; }
    void set_y(float value) { y = value; }
    void set_z(float value) { z = value; }

    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

    Vector3(float p_x, float p_y, float p_z) : x(p_x), y(p_y), z(p_z) {}

    ~Vector3() {}
};

inline const Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs)
{
    return Vector3(lhs.get_x() + rhs.get_x(),
                   lhs.get_y() + rhs.get_y(),
                   lhs.get_z() + rhs.get_z());
}

inline const Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs)
{
    return Vector3(lhs.get_x() - rhs.get_x(),
                   lhs.get_y() - rhs.get_y(),
                   lhs.get_z() - rhs.get_z());
}

inline const float dot(const Vector3 &lhs, const Vector3 &rhs)
{
    return lhs.get_x() * rhs.get_x() +
           lhs.get_y() * rhs.get_y() +
           lhs.get_z() * rhs.get_z();
}

inline const Vector3 cross(const Vector3 &lhs, const Vector3 &rhs)
{
    return Vector3(lhs.get_y() * rhs.get_z() - lhs.get_z() * rhs.get_y(),
                   lhs.get_z() * rhs.get_x() - lhs.get_x() * rhs.get_z(),
                   lhs.get_x() * rhs.get_y() - lhs.get_y() * rhs.get_x());
}

inline const Vector3 operator*(const Vector3 &lhs, float rhs)
{
    return Vector3(lhs.get_x() * rhs,
                   lhs.get_y() * rhs,
                   lhs.get_z() * rhs);
}

inline const Vector3 operator/(const Vector3 &lhs, float rhs)
{
    return Vector3(lhs.get_x() / rhs,
                   lhs.get_y() / rhs,
                   lhs.get_z() / rhs);
}

inline const float magnitude(const Vector3 &v)
{
    return sqrt(dot(v, v));
}

inline const Vector3 normalize(const Vector3 &v)
{
    return v / magnitude(v);
}

inline const float distance(const Vector3 &lhs, const Vector3 &rhs)
{
    return magnitude(lhs - rhs);
}

#endif
