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
    Numerical numerical(0.0001,-100, 0, -100, "potentialNum.png");//sets up the algorithm variables
    //(dimx,dimy,circle radius,potential of plates,tolerance)
    Analytic ana_alg(150,150,20,100,0.0001);//sets up the analytical variables
    Analytic num_alg(150,150,20,100,0.0001);//sets up the numerical values for an analytical solution

    // printPotential()/runElectric() arguments:
    // 1 => analytical plot
    // 2 => numerical with circle inside plot
    // 3 => numerical from an image plot  

    //find the numerical solution
    numerical.runAlgorithm();
    numerical.printPotential(3);
    numerical.runElectric(3);

    //find analytical solution
    ana_alg.runAnalytical();
    ana_alg.printPotential(1);

    //find analytical soltion numerically
    num_alg.runAlgorithm();
    num_alg.printPotential(2);
    num_alg.runElectric(2);
	
    //find the difference
    ana_alg.difference(num_alg);
    ana_alg.ratio(num_alg);

    
    Analyze analyze;

    //tolerance,potential,radius
    //analyze.compareIterations(0.0001,100,10);
    //tolerance,potential,radius
    //analyze.compMaxRatio(0.0001,100,10);
    //dim, potential, radius
    analyze.compTol(100,100,20);
    
    return 0;
}
