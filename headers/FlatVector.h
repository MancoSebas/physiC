#ifndef FLAT_VEC_H

#include <cmath>
#include <iostream>
#include <math.h>

// Create the FlatVector class
class FlatVector {
  public:
  float X;
  float Y;
    
  // constructor to initialize the vector
  FlatVector(float x, float y){
    this -> X = x;
    this -> Y = y;
  }

  // overload the << operator for printing FlatVector objects
  friend std::ostream& operator<<(std::ostream& out, const FlatVector& v) {
    out << "(" << v.X << "," << v.Y << ")";
    return out;
  }

  // overload the + operator to perform vector components sum
  inline FlatVector operator+(const FlatVector& a) {
    return FlatVector(this->X + a.X, this->Y + a.Y);
  }

  inline FlatVector operator-(const FlatVector& a){
    return FlatVector(this->X - a.X, this->Y - a.Y);
  }
};

#endif // !FLAT_VEC_H
