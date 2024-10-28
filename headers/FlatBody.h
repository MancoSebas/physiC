#ifndef FLAT_BODY

#include <cmath>
#include "FlatVector.h"

enum ShapeType {
    circle = 0,
    box = 1,
};

class FlatBody{
public: 
    FlatVector position;
    FlatVector linearVelocity;

    float rotation;
    float rotationalVelocity;
    
    float density; 
    float mass;
    float restitution; 
    float area;

    bool isStatic;
    
    float radius;
    float width; 
    float height;

    ShapeType shapeType;

    FlatBody(
        FlatVector position, 
        float density,
        float mass,
        float restitution,
        float area,
        bool isStatic,
        float radius,
        float width,
        float height,
        ShapeType shapeType
    ){
        this->position = position;
        this->linearVelocity = FlatVector(0,0);
        this->rotation = 0.0;
        this->rotationalVelocity = 0.0;

        this->density = density;
        this->mass = mass;
        this->restitution = restitution;
        this->area = area;

        this->isStatic = isStatic;
        this->radius = radius;
        this->width = width;
        this->height = height;
        this->shapeType = shapeType;
    }
};

#endif // !FLAT_BODY


