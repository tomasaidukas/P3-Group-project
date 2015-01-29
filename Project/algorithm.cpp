//Contains function definitions for Algorithm class

#include "algorithm.h"

//CONSTRUCTOR
// The arguments such as error should be done inside the algorithm by looking at the different between the adjacent level
// and when it satisfies the tolerance it should stop. Therefore, error here is used just for testing purposes for now.
Algorithm::Algorithm(double orp, double error, double tolerance){
	
	// V_Mesh is a 2D array to store the potential	
	Mesh V_Mesh(100,100);
	Mesh V_TempMesh(V_Mesh);
	
	double dimX = V_Mesh.getDimX();
	double dimY = V_Mesh.getDimY();
	
	V_Mesh.setAllZero();
	
	// Boundary conditions for the parallel plates
	for (int Y = 0 ; Y<dimY ; Y++){
		
		V_Mesh.setV(-10,0,Y);
		V_TempMesh.setV(-10,0,Y);
		V_Mesh.setV(10,dimX-1,Y);
		V_TempMesh.setV(10,dimX-1,Y);
	}
	
	// Zeroes everywhere else
	
	//**************************************//	
	// 		Over-relaxation algorithm		//	
	//**************************************//
	
	// Initialize the estimation of the solution one iteration ahead.
	for (int X = 1 ; X<dimX-1 ; X++){
		for (int Y = 1 ; Y<dimY-1 ; Y++){
			pot = (V_Mesh.getV(X+1,Y) + V_Mesh.getV(X-1,Y) + V_Mesh.getV(X,Y+1) + V_Mesh.getV(X,Y-1))/4;
			V_TempMesh.setV(pot,X,Y);
		}
	}
	
	// While the error is bigger than the tolerated one
	// carry on with approximating the solution further
	// until it is reached.
	while (error > tolerance){
	
		for (int X = 1 ; X<dimX-1 ; X++){
			for (int Y = 1 ; Y<dimY-1 ; Y++){
				pot = (1-orp)*V_Mesh.getV(X,Y) + (orp/4)*(V_Mesh.getV(X+1,Y) + V_TempMesh.getV(X,Y-1) + V_Mesh.getV(X,Y+1) + V_TempMesh.getV(X,Y-1));
				V_TempMesh.setV(pot,X,Y);		
			}
		}	
		
		// Set Potential = PotentialNEW
		for (int X = 1 ; X<dimX-1 ; X++){
			for (int Y = 1 ; Y<dimY-1 ; Y++){
				pot = V_Mesh.getV(X,Y);
				V_TempMesh.setV(pot,X,Y);	
			}
		}

		error -= 1;
	}
	
	
	
	
	


}

//DESTRUCTOR
Algorithm::~Algorithm(){}
