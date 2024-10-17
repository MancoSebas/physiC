#include <iostream>
#include "FlatVector.h"

int main(){

  FlatVector FlatVector1(3.0, 4.0);
  FlatVector FlatVector2(2.0, 6.0);
 
  FlatVector sumVector = FlatVector1 + FlatVector2;
  
  std::cout << sumVector << std::endl;

  return 0;
}
