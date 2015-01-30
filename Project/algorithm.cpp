//Contains function definitions for Algorithm class

#include "algorithm.h"

//CONSTRUCTOR
//sets up values to run in the algorithm
Algorithm::Algorithm(double d_orp, double d_error, double d_tolerance): md_orp(d_orp),
									     md_error(d_error),
									     md_tolerance(d_tolerance)
{
  V_Mesh = Mesh(100,100);
}








//RUN ALGORITHM
// The arguments such as error should be done inside the algorithm by looking at the different between the adjacent level
// and when it satisfies the tolerance it should stop. Therefore, error here is used just for testing purposes for now.
void Algorithm::runAlgorithm(){
	
	
	//**************************************//	
	// 	Set arrays for potential and field	//	
	//**************************************//
  
	Mesh V_TempMesh(V_Mesh);
	Mesh EF_dxMesh(V_Mesh);
	Mesh EF_dyMesh(V_Mesh);
	Mesh EF_Mesh(V_Mesh);
	
	// Make the Mesh zero initialy
	V_Mesh.setAllZero();
	
	// Variables for convenience
	double dimX = V_Mesh.getDimX();
	double dimY = V_Mesh.getDimY();
	
	
	//**************************************//	
	// 	Boundary conditions (for now)		//	
	//**************************************//
	for (int Y = 0 ; Y<dimY ; Y++){
		V_Mesh.setV(-10,0,Y);
		V_TempMesh.setV(-10,0,Y);
		V_Mesh.setV(10,dimX-1,Y);
		V_TempMesh.setV(10,dimX-1,Y);
	}
	
	//**************************************//	
	// 		Solution one iteration ahead	//
	//	 	using the Jacobi method			//	
	//**************************************//
	for (int X = 1 ; X<dimX-1 ; X++){
		for (int Y = 1 ; Y<dimY-1 ; Y++){
			pot = (V_Mesh.getV(X+1,Y) + V_Mesh.getV(X-1,Y) + V_Mesh.getV(X,Y+1) + V_Mesh.getV(X,Y-1))/4;
			V_TempMesh.setV(pot,X,Y);
		}
	}
	
	//**************************************//	
	//		Over-relaxation algorithm		//	
	//**************************************//
	// While the error is bigger than the tolerated one
	// carry on with approximating the solution further
	// until it is reached.
	while (md_error > md_tolerance){
		//main algorithm
		for (int X = 1 ; X<dimX-1 ; X++){
			for (int Y = 1 ; Y<dimY-1 ; Y++){
				pot = (1-md_orp)*V_Mesh.getV(X,Y) + (md_orp/4)*(V_Mesh.getV(X+1,Y) + V_TempMesh.getV(X-1,Y) + V_Mesh.getV(X,Y+1) + V_TempMesh.getV(X,Y-1));
				V_TempMesh.setV(pot,X,Y);		
			}
		}	
	// Set old potential = new potential
	V_Mesh.setEqual(V_TempMesh);
	// Approach the tolerance by 1
	md_error -= 1;
	}
	
	
	//**************************************//	
	// 			Electric field				//	
	//**************************************//
	for (int X = 0 ; X<dimX-1 ; X++){
		for (int Y = 0 ; Y<dimY-1 ; Y++){
			// Components of the electric field
			field = V_TempMesh.getV(X+1,Y) - V_TempMesh.getV(X,Y);
			EF_dxMesh.setV(field,X,Y);
			field =  V_TempMesh.getV(X,Y+1) - V_TempMesh.getV(X,Y); 
			EF_dyMesh.setV(field,X,Y);
			
			// Magnitude of E	
			field = sqrt(pow(EF_dxMesh.getV(X,Y),2) + pow(EF_dyMesh.getV(X,Y),2));
			EF_Mesh.setV(field,X,Y);
		}
	}
	
	//**************************************//	
	// 				Data files				//
	//**************************************//
	V_Mesh.PotentialData();
	EF_Mesh.FieldData(EF_dxMesh, EF_dyMesh);
}

//DESTRUCTOR
Algorithm::~Algorithm(){}



