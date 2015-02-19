#include "analyze.h"
#include "analytical.h"



/*************************************************
 * Outputs a text file with number of iterations 
 * vs dimensions this function runs an algorithm 
 * several times with varying dimensions and stores 
 * the data in a file. Compares time as well.
 *************************************************/
void Analyze::compareIterations(double tolerance, double potential, double radius){

    std::ofstream data;
    std::ofstream timedata;
    data.open("Analyze/VcompIterations.txt");
    timedata.open("Analyze/VcompTime.txt");
    
    //goes up to a 300 by 300 matrix
    for (int i=50; i<1051 ; i=i+100){
	Analytic anal1(i,i,radius,potential,tolerance);
	anal1.runAlgorithm();
	data << i << " " << anal1.getIter() << std::endl;
	timedata << i << " " << anal1.getTime() << std::endl;
    }
}  

/*************************************************
 * Takes the difference between two Meshes
 * and find the maximum
 *************************************************/
double Analyze::maxDiff(Analytic& num, Analytic& anal)
{   
    double differ = 0;
    for (int i=0; i<num._dimx; i++){
	for (int j=0; j<num._dimy; j++){
	    
	    double diff = fabs(num. _PMesh.getV(i,j) - anal._PMesh.getV(i,j) );
	    
	    if (differ < diff){
		differ = diff;
	    }
	}
    }

    return differ;
}

/*************************************************
 * Outputs text files with:
 * tolerance vs iterations
 * tolerance vs error
 * tolerance vs time
 * Change the 0.0001*i parameter to specify 
 * a tolerance range if you want 
 *************************************************/
void Analyze::compTol(double dim, double potential, double radius){

    std::ofstream datatol;
    std::ofstream dataerr,timedata;
    double err;
    
    datatol.open("Analyze/VcompTolerance.txt");
    dataerr.open("Analyze/VcompError.txt");
    timedata.open("Analyze/VcompTolTime.txt");
    //for (int i=10; i<10011 ; i=i+500){
	
	Analytic anal(dim,dim,radius,potential,0.01);
	Analytic num(dim,dim,radius,potential,0.01);
	num.runAlgorithm();
	anal.runAnalytical();
	
	err = num.difference(anal,0);
	
	//tolerance and iteration number
	datatol << 0.01 << " " << num.getIter() << std::endl;
	//tolerance and maximum error
	dataerr << 0.01 << " " << err << std::endl;

	timedata << 0.01 << " " << num.getTime() << std::endl;
    //}
}  





