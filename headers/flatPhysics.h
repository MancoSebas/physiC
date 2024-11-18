#ifndef FLAT_PHYSICS
#define FLAT_PHYSICS

#include "FlatBody.h"
#include "vec2.h"

class FlatPhysics{
public: 
   void freeFall(FlatBody &body, Vec2 initial_velocity, Vec2 acceleration, float time, float window_limit); 
};

#endif 
