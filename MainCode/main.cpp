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
  system("./run.sh &");

    //(tolerance,potential for RED,potential for GREEN,potential for BLUE,image name, scaling)
    Numerical numerical(0.01,-10, 0, -10, "potentialNum.png", 1);//sets up the algorithm variables
    
    //(dimx,dimy,circle radius,potential of plates,tolerance)
    Analytic ana_alg(100,100,25,1000,0.0000000001);//sets up the analytical variables
    Analytic num_alg(100,100,25,1000,0.0000000001);//sets up the numerical values for an analytical solution
    
    
    
    /********************************************
     * PLOTING EXPLAINED HERE
     * ******************************************
     * printROOT has more spaced out text data than
     * printGNUPLOT
     * 
    printROOT() arguments:
	1 => analytical plot
	2 => numerical with circle inside plot
	3 => numerical from an image plot  
     The plots can be generated by running ./PlotElectricField.sh 

    printGNUPLOT() first argument:
	1 => analytical plot
	2 => numerical with circle inside plot
	3 => numerical from an image plot  
    The plots can be generated by running ./PlotPotential.sh 
    ************************************************/
    
    
    /*******************************************
    * find numerical solution
    *******************************************/    
	std::cout << std::endl;
	numerical.runAlgorithm();
	numerical.printGNUPLOT(3);
	numerical.printROOT(3, 5);
	std::cout << "Iteration number for the numerical solution is: " << numerical.getIter() << std::endl;
	std::cout << "Algorithm ran for " << numerical.getTime() << " second(s)" << std::endl;
    
    /*******************************************
    * find analytical solution
    *******************************************/
	std::cout << std::endl;
	ana_alg.runAnalytical();
	ana_alg.printGNUPLOT(1);
	ana_alg.printROOT(1,5);
	std::cout << "Algorithm ran for " << ana_alg.getTime() << " second(s)" << std::endl;

    /*******************************************
    * find analytical soltion numerically
    *******************************************/
       std::cout << std::endl;
       num_alg.runAlgorithm();
       num_alg.printGNUPLOT(2);
       num_alg.printROOT(2,5);
       std::cout << "Iteration number for the analytical solution solved numerically is: " << num_alg.getIter() << std::endl;
       std::cout << "Algorithm ran for " << num_alg.getTime() << " second(s)" << std::endl;
       std::cout << "The average difference per mesh point as compared to the analytical solution is " << ana_alg.difference(num_alg,1) << "% of the total potential difference" << std::endl;
       std::cout << std::endl;
       
       
    
	
    /*******************************************
    * find the difference
    *******************************************/
	ana_alg.difference(num_alg, 1);
	
    /*******************************************
    * get iteration number and time
    *******************************************/
	
    
    /*******************************************
     * analyze results
    *******************************************/
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
    

    //Analyze analyze1;

    //tolerance,potential,radius
    //analyze1.compareIterations(0.01,1000,100);
    
    //Analyze analyze2;
    //dim, potential, radius
    //analyze2.compTol(100,100,10);
    
    system("./PLOT_ALL.sh");

    
    return 0;
}
