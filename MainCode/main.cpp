//default header files
#include<iostream>

//user-defined header files
#include "algorithm.h"
#include "analytical.h"
#include "mesh.h"
#include "topalg.h"
#include "CImg.h"


int main(){

  //(tolerance,potential,image name)
  Algorithm algorithm(0.0001,100,"potential.png");//sets up the algorithm variables
  Analytic ana_alg(50,50);//sets up the analytical variables
  //Analytic num_alg(50,50);//sets up the numerical values for an analytical solution

  // printSolution() arguments:
  // 1 => analytical plot
  // 2 => numerical with circle inside plot
  // 3 => numerical from an image plot  
  algorithm.runAlgorithm();
  algorithm.printSolution(3);

  ana_alg.runAlgorithm();
  ana_alg.printSolution(1);
  
  //num_alg.runNumerical();
 // ana_alg.printSolution(2);

  //ana_alg.difference(num_alg);
  return 0;
}
