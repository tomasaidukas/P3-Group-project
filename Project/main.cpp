//default header files
#include<iostream>

//user-defined header files
#include "mesh.h"
#include "algorithm.h"

int main(){
  Mesh mymesh(3,3);
  std::cin >> mymesh;
  std::cout << mymesh;
  
  Algorithm algorithm();
  
  return 0;
}
