//default header files
#include<iostream>

//user-defined header files
#include "numerical.h"
#include "analyze.h"
#include "analytical.h"
#include "mesh.h"
#include "topalg.h"
#include "CImg.h"


int main(){

  //(tolerance,potential,image name)
  Numerical numerical(0.0001,100,"potential.png");//sets up the algorithm variables
  //(dimx,dimy,circle radius,potential,tolerance)
  Analytic ana_alg(100,100,50,100,0.0001);//sets up the analytical variables
  Analytic num_alg(100,100,50,100,0.0001);//sets up the numerical values for an analytical solution

  // printSolution() arguments:
  // 1 => analytical plot
  // 2 => numerical with circle inside plot
  // 3 => numerical from an image plot  
  
  //find the numerical solution
  numerical.runAlgorithm();
  numerical.printSolution(3);

	//find analytical solution
  ana_alg.runAnalytical();
  ana_alg.printSolution(1);
  
  //find analytical soltion numerically
  num_alg.runAlgorithm();
  num_alg.printSolution(2);
	
  //find the difference
  ana_alg.difference(num_alg);
  ana_alg.ratio(num_alg);
  
  Analyze analyze;
  
  //analyze.compareIterations(0.0001,100,10);
  //analyze.compMaxDif(0.0001,100,10);
  return 0;
}
