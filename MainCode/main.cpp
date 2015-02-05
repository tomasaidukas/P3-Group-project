//default header files
#include<iostream>

//user-defined header files
#include "algorithm.h"
#include "mesh.h"
#include "CImg.h"


int main(){

	//(tolerance,potential,image name)
  Algorithm algorithm(0.0001,100,"50x50.png");//sets up the algorithm variables
  algorithm.runAlgorithm();
  //number of iterations taken to run the algorithm
  std::cout << algorithm.counter << std::endl;
  //ORP parameter
  std::cout << algorithm.md_orp << std::endl;
  return 0;
}
