//Contains function definitions for Algorithm class

#include "algorithm.h"

//CONSTRUCTOR
Algorithm::Algorithm(){
	
	
	// V_Mesh is a 2D array to store the potential
	V_Mesh = new Mesh(100,100);
	V_TempMesh = new Mesh(100,100);
	
	// Boundary conditions for the parallel plates
	for (int Y = 0 ; Y<dimY ; Y++){
		
		V_Mesh.=-10;
		V_TempMesh[0][Y]=-10;
		V_Mesh[dimX-1][Y]=10;
		potentialNEW[dimX-1][Y]=10;
	}
	


}

//DESTRUCTOR
Algorithm::~Algorithm(){}
