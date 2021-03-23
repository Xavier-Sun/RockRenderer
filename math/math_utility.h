#ifndef MATH_UTILITY_H
#define MATH_UTILITY_H

inline float max(float v1, float v2)
{
    return v1 > v2 ? v1 : v2;
}

inline float min(float v1, float v2)
{
    return v1 < v2 ? v1 : v2;
}

inline float max(float v1, float v2, float v3)
{
    return max(max(v1, v2), v3);
}

inline float min(float v1, float v2, float v3)
{
    return min(min(v1, v2), v3);
}

#endif
