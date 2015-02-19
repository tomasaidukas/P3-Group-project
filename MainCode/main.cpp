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

    //(tolerance,potential for RED,potential for GREEN,potential for BLUE,image name)
  Numerical numerical(0.01,-10, 0, -10, "potentialNum.png", 1);//sets up the algorithm variables
    //(dimx,dimy,circle radius,potential of plates,tolerance)
  //    Analytic ana_alg(1000,1000,100,1000,0.1);//sets up the analytical variables
  //    Analytic num_alg(1000,1000,100,1000,0.1);//sets up the numerical values for an analytical solution
    
    
    /*
    Analytic ana_alg1(1000,1000,100,1000,0.001);//sets up the analytical variables
    Analytic num_alg1(1000,1000,100,1000,0.001);//sets up the numerical values for an analytical solution

    Analytic ana_alg2(1000,1000,100,1000,0.01);//sets up the analytical variables
    Analytic num_alg2(1000,1000,100,1000,0.01);//sets up the numerical values for an analytical solution
    
    Analytic ana_alg3(1000,1000,100,1000,0.1);//sets up the analytical variables
    Analytic num_alg3(1000,1000,100,1000,0.1);//sets up the numerical values for an analytical solution
    
    
    ana_alg1.runAnalytical();
    ana_alg1.printPotential(1);
    num_alg1.runAlgorithm();
    num_alg1.printPotential(2);
    
    ana_alg2.runAnalytical();
    ana_alg2.printPotential(3);
    num_alg2.runAlgorithm();
    num_alg2.printPotential(4);
    
    ana_alg3.runAnalytical();
    ana_alg3.printPotential(6);
    num_alg3.runAlgorithm();
    num_alg3.printPotential(5);
    */
    
    // printPotential()/runElectric() arguments:
    // 1 => analytical plot
    // 2 => numerical with circle inside plot
    // 3 => numerical from an image plot  

    //find the numerical solution
    numerical.runAlgorithm();
    numerical.printPotential(3);
    numerical.runElectric(3);

    //find analytical solution
    //   ana_alg.runAnalytical();
    //   ana_alg.printPotential(1);

    //find analytical soltion numerically
    //   num_alg.runAlgorithm();
    //    num_alg.printPotential(2);
    //   num_alg.runElectric(2);
	
    //find the difference
    //    ana_alg.difference(num_alg, 1);
    //ana_alg.ratio(num_alg, 1);

    //Analyze analyze1;

    //tolerance,potential,radius
    //analyze1.compareIterations(0.01,1000,100);
    
    //Analyze analyze2;
    
    //dim, potential, radius
    //analyze2.compTol(1000,1000,100);
    
    return 0;
}
