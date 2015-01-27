#include<iostream>
#include "mesh.h"

int main(){
  Mesh mymesh(3,3);
  
  std::cin >> mymesh;
  std::cout << mymesh;
  return 0;
}
