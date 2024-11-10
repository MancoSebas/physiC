#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "vec2.h"

class Collisions{
public: 

    Vec2 normal;
    float depth;

    Collisions(){};

    bool intersectCircles(Vec2 centerA, float radiusA, Vec2 centerB, float radiusB);
};

#endif // !COLLISIONS_H


