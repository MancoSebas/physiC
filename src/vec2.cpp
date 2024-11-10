#include "../headers/vec2.h"

Vec2::Vec2(){};

Vec2::Vec2(float x, float y){ 
    this->X = x; 
    this->Y = y;
};

Vec2 Vec2::operator+(const Vec2 &v){
    return Vec2(this->X + v.X, this->Y + v.Y);
}

Vec2 Vec2::operator-(const Vec2 &v){
    return Vec2(this->X - v.X, this->Y - v.Y);
}

Vec2 Vec2::operator*(float a){
    return Vec2(this->X * a, this->Y * a);
}

Vec2 Vec2::operator/(float a){
    return Vec2(this->X / a, this->Y / a);
}



