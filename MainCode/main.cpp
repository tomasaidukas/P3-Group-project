//default header files
#include<iostream>

//user-defined header files
#include "algorithm.h"
#include "analytical.h"
#include "mesh.h"
#include "CImg.h"


int main(){

	//(tolerance,potential,image name)

  Algorithm algorithm(0.0001,100,"50x50.png");//sets up the algorithm variables
  
  algorithm.runAlgorithm();
  algorithm.printSolution();

  Analytic ana_alg(50,50);
  ana_alg.runAlgorithm();
  ana_alg.printSolution();
  return 0;
}
