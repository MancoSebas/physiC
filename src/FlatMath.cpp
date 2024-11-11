#include "../headers/FlatMath.h"
#include <SFML/Graphics/Glsl.hpp>
#include <cmath>
#include <iostream>

float FlatMath::length(Vec2 &v){
    float dx = v.X - 0.0f;
    float dy = v.Y - 0.0f;

    float length = std::sqrt(std::pow(dx,2) + std::pow(dy,2));
    return length;
}

float FlatMath::clamp(float value, float min, float max){
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

float FlatMath::distance(Vec2 &a, Vec2 &b){
    float dx = a.X - b.X;
    float dy = a.Y - b.Y;

    return std::sqrt(dx*dx + dy*dy);
}

Vec2 FlatMath::normalize(Vec2 v){
    float len = FlatMath().length(v);

    return Vec2(v.X / len, v.Y / len); 
}


float FlatMath::dot(Vec2 &a, Vec2 &b){
    return ((a.X * b.X) + (a.Y * b.Y));
}


Vec2 FlatMath::shifCoordinates(Vec2 &v, float screen_wdith, float screen_height){
    return Vec2(v.X + (screen_wdith / 2), -v.Y + (screen_height / 2));
}


/*
 
Vec2 primeCoordinates(Vec2 coordinates){
    return Vec2(coordinates.X + (float(SCREEN_WIDTH) / 2.0f), - coordinates.Y + (float(SCREEN_HEIGHT) / 2.0f));
}

*/
