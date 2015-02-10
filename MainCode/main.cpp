//default header files
#include<iostream>

//user-defined header files
#include "algorithm.h"
#include "mesh.h"
#include "CImg.h"


int main(){

	//(tolerance,potential,image name)
  Algorithm algorithm(0.0001,100,"potential.png");//sets up the algorithm variables
  algorithm.runAlgorithm();
  algorithm.printSolution();
  return 0;
}
