#include "analyze.h"
#include "analytical.h"

/*
//finds the maximum difference between the analytical and numerical solutions
void Analyze::compMaxDif(double tolerance, double potential, double radius){
  
  //largest difference value
  double ratio;
  double temp=0;
  std::ofstream data;
  data.open("VmaxRatio");
  
  for (int i=40 ; i<100 ; i=i+20){
    Analytic anal(i,i,radius,potential,tolerance);
    Analytic num(i,i,radius,potential,tolerance);
    
    for (int X = 0 ; X<_dimx ; X++){
      for (int Y = 0 ; Y<_dimy ; Y++){
	if (!num._PMesh.getisBoundary(X,Y) && !anal._PMesh.getisBoundary(X,Y)){

	  ratio = fabs(anal._PMesh.getV(X,Y) / num._PMesh.getV(X,Y));
	  std::cout << ratio << std::endl;
	
	  //find the largest difference value
	  if (temp < ratio){
	    temp = ratio;
	    std::cout << temp << std::endl;
	  }
	  
	}
      }
    }
    //dimensions, maximum difference
    data << i << " " << temp << std::endl;
  }
}*/











/*************************************************
 * Outputs a text file with number of iterations 
 * vs dimensions this function runs an algorithm 
 * several times with varying dimensions and stores 
 * the data in a file
 *************************************************/
void Analyze::compareIterations(double tolerance, double potential, double radius){

    std::ofstream data;
    data.open("Analyze/VcompIterations.txt");

    //goes up to a 500 by 500 matrix
    for (int i=20; i<300 ; i=i+20){
	Analytic anal(i,i,radius,potential,tolerance);
	anal.runAlgorithm();
	data << i << " " << anal.getIter() << std::endl;
    }
}  
