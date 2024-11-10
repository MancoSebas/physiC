#ifndef VEC2_H
#define VEC2_H

#include <ostream>

class Vec2 {
public: 
    float X;
    float Y;

    Vec2();

    Vec2(float x, float y);

    friend std::ostream &operator<<(std::ostream &out, const Vec2 &v){
        return out << "[" << v.X << "," << v.Y << "]";
    };

    Vec2 operator+(const Vec2 &a);

    Vec2 operator-(const Vec2 &a);

    Vec2 operator*(float a);

    Vec2 operator/(float a);
};


#endif // !VEC2_H
