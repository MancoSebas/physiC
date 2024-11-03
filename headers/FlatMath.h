#include <iostream>
#ifndef FLAT_MATH_H

#include <cmath>
#include "FlatVector.h"

class FlatMath{
public:

  float Length(FlatVector v){
    float dx = v.X - 0.0f;
    float dy = v.Y - 0.0f;

    float length = sqrt(pow(dx,2) + pow(dy,2));
    return length;
  }  

    float clamp(float value, float min, float max){
        if (min == max) {
            return min; 
        }

        if (min > max) {
            return min; 
            std::cerr << "max should be greater than min" << std::endl;
        }

        if (value < min) {
            return min; 
        }

        if (value > max) {
            return max;  
        }

        return value;
    }

    float Distance(FlatVector a, FlatVector b){
        float dx = a.X - b.X;
        float dy = a.Y - b.Y;

        return sqrt(dx*dx + dy*dy);
    }

    FlatVector Normalize(FlatVector v){
        float len = FlatMath().Length(v);

        return FlatVector(v.X / len, v.Y / len); 
    }

    float Dot(FlatVector a, FlatVector b){
        return ((a.X * b.X) + (a.Y * b.Y));
    }
};

#endif // !FLAT_MATH_H

