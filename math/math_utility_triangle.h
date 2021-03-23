#ifndef MATH_UTILITY_TRIANGLE_H
#define MATH_UTILITY_TRIANGLE_H

#include "math/vector2.h"
#include "math/vector3.h"

inline bool point_in_triangle(const Vector2 &point, const Vector2 &v1, const Vector2 &v2, const Vector2 &v3)
{
    Vector2 v1v2 = v2 - v1;
    Vector2 v2v3 = v3 - v2;
    Vector2 v3v1 = v1 - v3;

    Vector2 v1pos = point - v1;
    Vector2 v2pos = point - v2;
    Vector2 v3pos = point - v3;

    float result1 = cross(Vector3(v1v2.get_x(), v1v2.get_y(), 0.0f), Vector3(v1pos.get_x(), v1pos.get_y(), 0.0f)).get_z();
    float result2 = cross(Vector3(v2v3.get_x(), v2v3.get_y(), 0.0f), Vector3(v2pos.get_x(), v2pos.get_y(), 0.0f)).get_z();
    float result3 = cross(Vector3(v3v1.get_x(), v3v1.get_y(), 0.0f), Vector3(v3pos.get_x(), v3pos.get_y(), 0.0f)).get_z();

    return (result1 > 0 && result2 > 0 && result3 > 0) || (result1 < 0 && result2 < 0 && result3 < 0);
}

inline Vector3 get_barycentric_coordinate(const Vector2 &point, const Vector2 &v1, const Vector2 &v2, const Vector2 &v3)
{
    float a = ((v2.get_x() - point.get_x()) * (v3.get_y() - v2.get_y()) +
               (point.get_y() - v2.get_y()) * (v3.get_x() - v2.get_x())) /
              ((v2.get_x() - v1.get_x()) * (v3.get_y() - v2.get_y()) +
               (v1.get_y() - v2.get_y()) * (v3.get_x() - v2.get_x()));

    float b = ((v3.get_x() - point.get_x()) * (v1.get_y() - v3.get_y()) +
               (point.get_y() - v3.get_y()) * (v1.get_x() - v3.get_x())) /
              ((v3.get_x() - v2.get_x()) * (v1.get_y() - v3.get_y()) +
               (v2.get_y() - v3.get_y()) * (v1.get_x() - v3.get_x()));

    float c = 1.0f - a - b;

    return Vector3(a, b, c);
}

#endif
