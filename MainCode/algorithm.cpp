#include "algorithm.h"

//CONSTRUCTOR
//sets up values to run in the algorithm
Algorithm::Algorithm(double d_orp, double d_error, double d_tolerance): md_orp(d_orp),
									     md_error(d_error),
									     md_tolerance(d_tolerance)
{
  //load the image
  image.load("potential.png");
  
  //image dimensions
  a_dimY = image.height();  
  a_dimX = image.width();
  
  //allocate dimensions to new arrays
  V_Mesh.Allocate(a_dimX,a_dimY);
  V_TempMesh.Allocate(a_dimX,a_dimY);
  EF_dxMesh.Allocate(a_dimX,a_dimY);
  EF_dyMesh.Allocate(a_dimX,a_dimY);
  EF_Mesh.Allocate(a_dimX,a_dimY);
  
  //set all values to zero initialy
  V_Mesh.setAllZero();
  //set the boundaries  
  setBoundary(10);
  
  //set the same boundary conditions on temp mesh as well
  V_Mesh.setEqual(V_TempMesh);
}


//**************************************//	
// 		Set the boundaries				//
//**************************************//
void Algorithm::setBoundary(double pot)
{
  // set the boundaries from an image file
	for (int x=0 ; x<a_dimX-1 ; x++){
		for (int y=0 ; y<a_dimY-1 ; y++){
			if( ((int) image(x,y,0,0) == 255) && ((int)image(x,y,0,1)==0) && ((int)image(x,y,0,2) == 0) ){
				//V_Mesh.setV(pot,x,y);
				V_TempMesh.setV(pot,x,y);
			}else if( ((int) image(x,y,0,0) == 0) && ((int)image(x,y,0,1)==255) && ((int)image(x,y,0,2) == 0) ){
				//V_Mesh.setV(0,x,y); 
				V_TempMesh.setV(0,x,y);
			}else if( ((int) image(x,y,0,0) == 0) && ((int)image(x,y,0,1)==0) && ((int)image(x,y,0,2) == 255) ){
				//V_Mesh.setV(-pot,x,y);
				V_TempMesh.setV(-pot,x,y);
			}
		}
	}
 }



//**************************************//	
// 		Executes the algorithm			//
//**************************************//
void Algorithm::runAlgorithm(){
	//**************************************//	
	// 		Solution one iteration ahead	//
	//	 	using the Jacobi method			//	
	//**************************************//
	for (int X = 1 ; X<a_dimX-1 ; X++){
		for (int Y = 1 ; Y<a_dimY-1 ; Y++){
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
		for (int X = 1 ; X<a_dimX-1 ; X++){
			for (int Y = 1 ; Y<a_dimY-1 ; Y++){
				setBoundary(10);
				
				md_pot = (1-md_orp)*V_Mesh.getV(X,Y) + (md_orp/4)*(V_Mesh.getV(X+1,Y) + V_TempMesh.getV(X-1,Y) + V_Mesh.getV(X,Y+1) + V_TempMesh.getV(X,Y-1));
				V_TempMesh.setV(md_pot,X,Y);		
			}
		}	
	// Set old potential = new potential
	V_Mesh.setEqual(V_TempMesh);
	md_error -= 1;
	}
	
	//**************************************//	
	// 			Electric field				//	
	//**************************************//
	for (int X = 0 ; X<a_dimX-1 ; X++){
		for (int Y = 0 ; Y<a_dimY-1 ; Y++){
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



Algorithm::~Algorithm(){}
