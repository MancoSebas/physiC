#ifndef BODY_H
#define BODY_H

#include "vec2.h"
#include <array>

enum ShapeType{
    circle = 0, 
    box = 1,
};

class FlatBody{
public: 
    Vec2 position {};
    Vec2 linearVelocity {};
    std::array<Vec2, 4> vertices {};
    std::array<Vec2, 4> transformedVertices {}; 

    float rotation; 
    float rotationVelocity;

    float density;
    float mass; 
    float restitution;
    float area; 

    bool isStatic;

    float radius; 
    float width; 
    float height;

    ShapeType shapeType;

    FlatBody(){};

    FlatBody(
        Vec2 position,
        float density,
        float mass,
        float restitution,
        float area,
        bool isStatic,
        float radius,
        float width,
        float height,
        ShapeType shapeType
    );

    std::array<Vec2,4> createBoxVertices(float width, float height); 
    
    void move(Vec2 dv);
    
    FlatBody createCircleBody(float raidus, Vec2 position, float density, bool isStatic, float restitution);
}; 

#endif // !BODY_H
