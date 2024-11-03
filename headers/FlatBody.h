#include "FlatWorld.h"
#ifndef FLAT_BODY

#include <cmath>
#include "FlatVector.h"
#include <math.h>

enum ShapeType {
    circle = 0,
    box = 1,
};

class FlatBody{
public: 
    FlatVector position = FlatVector(0.0f,0.0f);
    FlatVector linearVelocity = FlatVector(0.0f,0.0f);

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
        this->linearVelocity = FlatVector(0.0f,0.0f); 
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


    bool createCircleBody(float radius, FlatVector position, float density, bool isStatic, float restitution){
       
        float area = radius * radius * M_PI;

        if (area < FlatWorld().minBodySize) {
            return false;
        }

        if (area > FlatWorld().maxBodySize) {
            return false;
        }

        if (density < FlatWorld().minDensity) {
            return false; 
        }

        if (density > FlatWorld().maxDensity) {
            return false;  
        } 

        FlatBody body = FlatBody(position,density,mass, restitution, area, isStatic, radius, width, height, shapeType);
        return true; 
    }

};

#endif // !FLAT_BODY


