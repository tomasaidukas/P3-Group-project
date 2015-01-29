//Contains function definitions for Algorithm class

#include "algorithm.h"

//CONSTRUCTOR
Algorithm::Algorithm(){
	
	//// orp
	orp=1.5;
	error = 500;
	
	// V_Mesh is a 2D array to store the potential
	V_Mesh = new Mesh(100,100);
	V_TempMesh = new Mesh(100,100);
	
	dimX = V_Mesh.mn_dimX;
	dimY = V_Mesh.mn_dimY;
	
	// Boundary conditions for the parallel plates
	for (int Y = 0 ; Y<dimY ; Y++){
		
		V_Mesh.setV(-10,0,Y);
		V_TempMesh.setV(-10,0,Y);
		V_Mesh.setV(10,dimX-1,Y);
		V_TempMesh.setV(10,dimX-1,Y);
	}
	
	// Zeroes everywhere else
	for (int X = 1 ; X<dimX-1 ; X++){
		for (int Y = 0 ; Y<dimY ; Y++){	
			V_Mesh.setV(0,X,Y);
		}
	}
	
	
	
	


}

//DESTRUCTOR
Algorithm::~Algorithm(){}
