#include "../headers/FlatBody.h"
#include "../headers/FlatWorld.h"
#include "../headers/FlatMath.h"
#include <cctype>
#include <cmath>
#include <stdexcept>

FlatBody::FlatBody(
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
){
    this->position = position;
    this->density = density;
    this->mass = mass; 
    this->restitution = restitution;
    this->area = area;
    this->isStatic = isStatic;
    this->radius = radius;
    this->width = width; 
    this->height = height; 
    this->shapeType = shapeType;

    if (this->shapeType == ShapeType::circle) {
    }
}

std::array<Vec2, 4> FlatBody::createBoxVertices(float widht, float height){
    float left = -width / 2.0f;
    float right = left + width; 
    float bottom = -height / 2.0f; 
    float top = bottom + height; 

    std::array<Vec2, 4> vertices {};  
    vertices[0] = Vec2(left,top);
    vertices[1] = Vec2(right,top);
    vertices[2] = Vec2(left,bottom);
    vertices[3] = Vec2(right,bottom);

    return vertices;
}

void FlatBody::move(Vec2 dv){
    this->position = this->position + dv;
}

FlatBody FlatBody::createCircleBody(float radius, Vec2 position, float density, bool isStatic, float restitution){
    float area = radius * radius * M_PI;
    
    if (area < FlatWorld().minBodySize ) {
        throw std::invalid_argument("Circle raidus is too low");
    }
    if (area > FlatWorld().maxBodySize){
        throw std::invalid_argument("Circle radus is too high");
    }

    if (density < FlatWorld().minDensity){
        throw std::invalid_argument("Density must be greater than the min density");
    }

    if (density > FlatWorld().maxDensity){
        throw std::invalid_argument("Density must be smaller that the max density");
    }

    restitution = FlatMath().clamp(restitution, 0.0f, 1.0f);

    float mass = area * density;

    return FlatBody(position,density,mass,restitution,area, isStatic,radius, 0.0f, 0.0f, ShapeType::circle);
    
}
