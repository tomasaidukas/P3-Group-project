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
    for (int i=20; i<300 ; i=i+20){
	Analytic anal(i,i,radius,potential,tolerance);
	anal.runAlgorithm();
	data << i << " " << anal.getIter() << std::endl;
	timedata << i << " " << anal.getTime() << std::endl;
    }
}  

/*************************************************
 * Outputs a text file with tolerance 
 * vs iterations AND text file with tolerance
 * vs error.
 *************************************************/
void Analyze::compTol(double dim, double potential, double radius){

    std::ofstream datatol;
    std::ofstream dataerr;
    double err;
    
    datatol.open("Analyze/VcompTolerance.txt");
    dataerr.open("Analyze/VcompError.txt");
    for (int i=10; i<1000 ; i=i+100){
	
	Analytic anal(dim,dim,radius,potential,double(1)/i);
	Analytic num(dim,dim,radius,potential,double(1)/i);
	num.runAlgorithm();
	anal.runAnalytical();
	
	err = anal.maxDiff(num);
	
	//tolerance and iteration number
	datatol << double(1)/i << " " << num.getIter() << std::endl;
	//tolerance and maximum error
	std::cout << double(1)/i << std::endl;
	dataerr << double(1)/i << " " << err << std::endl;
    }
}  





