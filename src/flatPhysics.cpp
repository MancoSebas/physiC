#include "../headers/vec2.h"
#include "../headers/flatPhysics.h"

void FlatPhysics::freeFall(FlatBody &body, Vec2 initial_velocity, Vec2 acceleration, float time, float window_limit){
    float yPosition = body.position.Y;
    
    if (yPosition < window_limit) {
        body.move(initial_velocity + acceleration*time);
    }
}
