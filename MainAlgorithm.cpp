#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

#define PI 3.141592653

double relaxation(int,int,double);

// Algorithm for Succesive over-relaxation
// Takes two coordinates as an argument
// and the error tolerance.

double relaxation(int dimX, int dimY, double tolerance){
	
	//**************************************//	
	// 	Initialize variables		//	
	//**************************************//
	
	// Over-relaxation parameter
	double orp;
	// Iterator
	int N;
	// Error
	double error;
	// File for the data
	ofstream data;
	
	double xMiddle,yMiddle;
	

	
	//**************************************//
	// Initialize a matrix of arbitrary size//
	// With dimensions X and Y, which can be//
	// specified by the user		//
	//**************************************//
	
		
	double** potential;
	double** potentialNEW;
	potential = new double*[dimX];
	potentialNEW = new double*[dimX];
	
	// Each pointer will point to an array of size Y
	// hence, this will create an array of arrays OR in other words a 2D array
	for(int i=0 ; i<dimY ; i++){
		potential[i] = new double[dimY];	
		potentialNEW[i] = new double[dimY];	
	}
	
	
	//**************************************//	
	// 	Initialize the boundaries	//	
	//**************************************//
	
	// Boundary conditions for the parallel plates
	for (int Y = 0 ; Y<dimY ; Y++){
		
		potential[0][Y]=-10;
		potentialNEW[0][Y]=-10;
		potential[dimX-1][Y]=10;
		potentialNEW[dimX-1][Y]=10;
	}
	
	
	
	// Zeroes everywhere else
	for (int X = 1 ; X<dimX-1 ; X++){
		for (int Y = 0 ; Y<dimY ; Y++){	
			potential[X][Y]=0;
		}
	}
	

	
	
	// Middle coordinates of the circle
	xMiddle = round(dimX/2);
	yMiddle = round(dimY/2);
	
	// Radius

	int R = 20;
	
	// Circle in the middle
	/*
	for (int X = (xMiddle - R) ; X<(xMiddle + R); X++){
		for (int Y = (yMiddle - R) ; Y<(yMiddle + R) ; Y++){
			if ( pow(X,2) + pow(Y,2) <= pow(R,2) ) {	
				potential[X][Y]=0;
				potentialNEW[X][Y]=0;
			}
		}
	}
	*/
	
	
	
	//**************************************//	
	// 	Over-relaxation parameter	//	
	//**************************************//
	
	// The algorithm converges the fastest when 
	// orp = 2/(1 + PI/L)
	//orp = 2/(1 + PI/dimX);
	orp=1.5;
	
	
	//**************************************//	
	// 	Over-relaxation algorithm	//	
	//**************************************//
	
	// Initialize the estimation of the solution one iteration ahead.
	for (int X = 1 ; X<dimX-1 ; X++){
		for (int Y = 1 ; Y<dimY-1 ; Y++){
			if ( pow(X-xMiddle,2) + pow(Y-yMiddle,2) <= pow(R,2) ) {
				potentialNEW[X][Y] = 0;
			} else {		
				potentialNEW[X][Y] = (potential[X+1][Y] + potential[X-1][Y] + potential[X][Y+1] + potential[X][Y-1])/4;
			}
		}
	}
	

	
	
	
	// While the error is bigger than the tolerated one
	// carry on with approximating the solution further
	// until it is reached.
	error = 500;
	while (error > tolerance){
	
		for (int X = 1 ; X<dimX-1 ; X++){
			for (int Y = 1 ; Y<dimY-1 ; Y++){
				if ( pow(X-xMiddle,2) + pow(Y-yMiddle,2) <= pow(R,2) ) {
					potentialNEW[X][Y] = 0;
				} else {
					potentialNEW[X][Y] = (1-orp)*potential[X][Y] + (orp/4)*(potential[X+1][Y] + potentialNEW[X-1][Y] + potential[X][Y+1] + potentialNEW[X][Y-1]);
				}
			}
		}	
		
		
		// Set Potential = PotentialNEW
		for (int X = 1 ; X<dimX-1 ; X++){
			for (int Y = 1 ; Y<dimY-1 ; Y++){
				potential[X][Y] = potentialNEW[X][Y];	
			}
		}

		error -= 1;
		
		
		
	}

	data.open ("code");

	for (int X = 0 ; X<dimX ; X++){
		for (int Y = 0 ; Y<dimY ; Y++){
			data << X << " " << Y << " " << potentialNEW[X][Y] << endl ;
		}
	}
	

	
	return 0;
}





int main(){


	relaxation(50,200,1);
	return 0;
}