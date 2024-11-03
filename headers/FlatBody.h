#include "FlatWorld.h"
#include <stdexcept>
#ifndef FLAT_BODY

#include <cmath>
#include "FlatMath.h"
////#include "FlatVector.h"
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

    FlatBody(){};

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


    FlatBody createCircleBody(float radius, FlatVector position, float density, bool isStatic, float restitution){
       
        float area = radius * radius * M_PI;

        if (area < FlatWorld().minBodySize) {
            std::invalid_argument("body size must be greater than the minimum");
        }

        if (area > FlatWorld().maxBodySize) {
            std::invalid_argument("body size must be smaller than the maximum");
        }

        if (density < FlatWorld().minDensity) {
            std::invalid_argument("body density must be greater than the minimum density");
        }

        if (density > FlatWorld().maxDensity) {
            std::invalid_argument("body density must be smaller than the maximum density");
        } 

        restitution = FlatMath().clamp(restitution, 0.0f, 1.0f);
        
        float mass = area * density;


        std::cout << "creating circle body" << std::endl;
        
        return FlatBody(position,density,mass, restitution, area, isStatic, radius, 0.0f, 0.0f, ShapeType::circle);
    }

    FlatBody createBox(float width, float height, FlatVector position, float density, bool isStatic, float restitution){

        float area = width * height;

        if (area < FlatWorld().minBodySize) {
            std::invalid_argument("body size must be greater than the minimum");
        }

        if (area > FlatWorld().maxBodySize) {
            std::invalid_argument("body size must be smaller than the maximum");
        }

        if (density < FlatWorld().minDensity) {
            std::invalid_argument("body density must be greater than the minimum density");
        }

        if (density > FlatWorld().maxDensity) {
            std::invalid_argument("body density must be smaller than the maximum density");
        } 

        restitution = FlatMath().clamp(restitution, 0.0f, 1.0f);
        float mass = area * density; 
        
        return FlatBody(position, density, mass, restitution, area, isStatic, 0.0f, width, height, ShapeType::box);
    }

};

#endif // !FLAT_BODY


