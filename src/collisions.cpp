#include "../headers/collisions.h"
#include "../headers/FlatMath.h"

bool Collisions::intersectCircles(Vec2 centerA, float radisusA, Vec2 centerB, float radiusB){
    float distance = FlatMath().distance(centerA, centerB);
    float radii = radisusA + radiusB;

    if (distance >= radii) {
        return false;  
    }

    Vec2 normal = Vec2(centerB - centerA);
    this->normal = FlatMath().normalize(centerB - centerA);
    this->depth = radii - distance;

    return true;
}
