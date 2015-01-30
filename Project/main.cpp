//default header files
#include<iostream>

//user-defined header files
#include "mesh.h"
#include "algorithm.h"

int main(){

/*
  Mesh mymesh(3,3);
  std::cin >> mymesh;
  std::cout << mymesh;
  */
  
  Algorithm algorithm(1.5,500,1);//sets up the algorithm variables
  
  algorithm.runAlgorithm();//runs the algorithm
  
  return 0;
}
