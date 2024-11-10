#ifndef MATH_H
#define MATH_H

#include "vec2.h"

class FlatMath{
public:

    float length(Vec2 &v);  

    float clamp(float value, float min, float max);

    float distance(Vec2 &a, Vec2 &b);

    Vec2 normalize(Vec2 v);

    float dot(Vec2 &a, Vec2 &b);
};

#endif // !MATH_H

