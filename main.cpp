#include <iostream>
#include "FlatMath.h" 
//#include "FlatVector.h"

int main(){

  FlatVector FlatVector1(3.0, 4.0);
  FlatVector FlatVector2(2.0, 6.0);
 
  FlatVector sumVector = FlatVector1 + FlatVector2;
  
  std::cout << sumVector << std::endl;
  std::cout << sumVector.Length() << std::endl; 
  std::cout << FlatMath().Normalize(sumVector) << std::endl; 
  std::cout << FlatMath().Dot(FlatVector1,FlatVector2) << std::endl;

  return 0;
 }
