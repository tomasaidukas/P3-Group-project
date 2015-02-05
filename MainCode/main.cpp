//default header files
#include<iostream>

//user-defined header files
#include "algorithm.h"
#include "mesh.h"
#include "CImg.h"


int main(){

  Algorithm algorithm(0.0001,100);//sets up the algorithm variables
  algorithm.runAlgorithm();
  std::cout << algorithm.counter << std::endl;
  return 0;
}
