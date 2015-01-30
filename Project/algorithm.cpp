//Contains function definitions for Algorithm class

#include "algorithm.h"

//CONSTRUCTOR
//sets up values to run in the algorithm
Algorithm::Algorithm(double d_orp, double d_error, double d_tolerance): md_orp(d_orp),
									     md_error(d_error),
									     md_tolerance(d_tolerance)
{
  //user enters dimensions of mesh
  std::cout << "Enter Mesh Dimensions AxB" << std::endl;
  std::cout << "A: ";
  std::cin >> mn_dimX;
  std::cout << "B: ";
  std::cin >> mn_dimY;
  
  //initialise primary mesh
  V_Mesh = Mesh(mn_dimX,mn_dimY);
  V_Mesh.setAllZero();
  
  //set the boundary conditions
  setBoundary();
  
  //copy boundary conditions to secondary mesh
  V_TempMesh = Mesh(V_Mesh);
}


//SET BOUNDARY
//sets the boundary conditions before the algorithm runs
void Algorithm::setBoundary()
{
  //current boundary conditions
  for (int j=0; j<mn_dimY; j++){
    V_Mesh.setisBoundary(1,0,j);//x=0
    V_Mesh.setV(-10,0,j);

    V_Mesh.setisBoundary(1,mn_dimX-1,j);//x=mn_dimX-1
    V_Mesh.setV(10,mn_dimX-1,j);
  }
}











//RUN ALGORITHM
// The arguments such as error should be done inside the algorithm by looking at the different between the adjacent level
// and when it satisfies the tolerance it should stop. Therefore, error here is used just for testing purposes for now.
void Algorithm::runAlgorithm(){
	
	
	//**************************************//	
	// 	Set arrays for potential and field	//	
	//**************************************//
  
	Mesh EF_dxMesh(V_Mesh);
	Mesh EF_dyMesh(V_Mesh);
	Mesh EF_Mesh(V_Mesh);
	
	//**************************************//	
	// 		Solution one iteration ahead	//
	//	 	using the Jacobi method			//	
	//**************************************//
	for (int X = 1 ; X<mn_dimX-1 ; X++){
		for (int Y = 1 ; Y<mn_dimY-1 ; Y++){
			md_pot = (V_Mesh.getV(X+1,Y) + V_Mesh.getV(X-1,Y) + V_Mesh.getV(X,Y+1) + V_Mesh.getV(X,Y-1))/4;
			V_TempMesh.setV(md_pot,X,Y);
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
		for (int X = 1 ; X<mn_dimX-1 ; X++){
			for (int Y = 1 ; Y<mn_dimY-1 ; Y++){
				md_pot = (1-md_orp)*V_Mesh.getV(X,Y) + (md_orp/4)*(V_Mesh.getV(X+1,Y) + V_TempMesh.getV(X-1,Y) + V_Mesh.getV(X,Y+1) + V_TempMesh.getV(X,Y-1));
				V_TempMesh.setV(md_pot,X,Y);		
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
	for (int X = 0 ; X<mn_dimX-1 ; X++){
		for (int Y = 0 ; Y<mn_dimY-1 ; Y++){
			// Components of the electric field
			md_field = V_TempMesh.getV(X+1,Y) - V_TempMesh.getV(X,Y);
			EF_dxMesh.setV(md_field,X,Y);
			md_field =  V_TempMesh.getV(X,Y+1) - V_TempMesh.getV(X,Y); 
			EF_dyMesh.setV(md_field,X,Y);
			
			// Magnitude of E	
			md_field = sqrt(pow(EF_dxMesh.getV(X,Y),2) + pow(EF_dyMesh.getV(X,Y),2));
			EF_Mesh.setV(md_field,X,Y);
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



