#include "algorithm.h"


//**************************************//	
//	 		CONSTRUCTOR 				//
//**************************************//
Algorithm::Algorithm(double d_tolerance, double d_voltage, std::string str):md_tolerance(d_tolerance),md_voltage(d_voltage)
{
  //load the image
  image.load(str.c_str());
  
  //image dimensions
  a_dimX = image.height();  
  a_dimY = image.width();
  
  //allocate dimensions to new arrays
  V_Mesh.Allocate(a_dimX,a_dimY);
  V_TempMesh.Allocate(a_dimX,a_dimY);
  EF_dxMesh.Allocate(a_dimX,a_dimY);
  EF_dyMesh.Allocate(a_dimX,a_dimY);
  EF_Mesh.Allocate(a_dimX,a_dimY);
  
  //set all values to zero initialy
  V_Mesh.setAllZero();
  
  //set the boundaries  
  setBoundary(md_voltage);
  
  //calculate the over-relaxation parameter
  //which depends on the array size
  ORP();
  
  //counter to see total number of iterations
  counter = 0;
  
  //set the same boundary conditions on temp mesh as well
  V_Mesh.setEqual(V_TempMesh);
}


//**************************************//	
// 		Set the boundaries				//
//**************************************//
void Algorithm::setBoundary(double pot)
{
  // set the boundaries from an image file
	for (int y=0 ; y<a_dimX-1 ; y++){
		for (int x=0 ; x<a_dimY-1 ; x++){
			if( ((int) image(x,y,0,0) == 255) && ((int)image(x,y,0,1)==0) && ((int)image(x,y,0,2) == 0) ){
				V_Mesh.setV(pot,x,y);
				V_Mesh.setisBoundary(true, x, y);
				V_TempMesh.setV(pot,x,y);
				V_TempMesh.setisBoundary(true, x, y);
			}else if( ((int) image(x,y,0,0) == 0) && ((int)image(x,y,0,1)==255) && ((int)image(x,y,0,2) == 0) ){
				V_Mesh.setV(0,x,y); 
				V_Mesh.setisBoundary(true, x, y);
				V_TempMesh.setV(0,x,y);
				V_TempMesh.setisBoundary(true, x, y);
			}else if( ((int) image(x,y,0,0) == 0) && ((int)image(x,y,0,1)==0) && ((int)image(x,y,0,2) == 255) ){
				V_Mesh.setV(-pot,x,y);
				V_Mesh.setisBoundary(true, x, y);
				V_TempMesh.setV(-pot,x,y);
				V_TempMesh.setisBoundary(true, x, y);
			}
		}
	}
 }



//**************************************//	
// 		Executes the algorithm			//
//**************************************//
void Algorithm::runAlgorithm(){
	// 		Solution one iteration ahead
	//	 	using the Jacobi method	
	for (int X = 1 ; X<a_dimX-1 ; X++){
		for (int Y = 1 ; Y<a_dimY-1 ; Y++){
			md_pot = (V_Mesh.getV(X+1,Y) + V_Mesh.getV(X-1,Y) + V_Mesh.getV(X,Y+1) + V_Mesh.getV(X,Y-1))/4;
			V_TempMesh.setV(md_pot,X,Y);
		}
	}
	//	Over-relaxation algorithm
	// While the error is bigger than the tolerated one
	// carry on with approximating the solution further
	// until it is reached.
	calcError(V_TempMesh,V_Mesh);
	//calculate the error between two meshes
	while (md_error > md_tolerance){
		//main algorithm
		for (int X = 1 ; X<a_dimX-1 ; X++){
			for (int Y = 1 ; Y<a_dimY-1 ; Y++){
			  if (!V_TempMesh.getisBoundary(X,Y)){
			 	 md_pot = (1-md_orp)*V_Mesh.getV(X,Y) + (md_orp/4)*(V_Mesh.getV(X+1,Y) + V_TempMesh.getV(X-1,Y) + V_Mesh.getV(X,Y+1) + V_TempMesh.getV(X,Y-1));
					//set the edges between the plates to be equal to their neighbours to eliminate the zeroes.
					//if(X==1){
					//	V_TempMesh.setV(md_pot,X-1,0);
					//}else if(X==a_dimX-1){
					//	V_TempMesh.setv(md_pot,a_dimX,
				
				V_TempMesh.setV(md_pot,X,Y);
			  }	
			  
			}
		}
		calcError(V_TempMesh,V_Mesh);
		// Set old potential = new potential
		V_Mesh.setEqual(V_TempMesh);
	}
	//calculate the e.field arrays
	eField(V_TempMesh);
	//	Put the mesh values to a data file
	V_Mesh.PotentialData();
	EF_Mesh.FieldData(EF_dxMesh, EF_dyMesh);
}




//**************************************//	
//	Electric field array calculator		//	
//**************************************//
void Algorithm::eField(Mesh& array){
	for (int X = 0 ; X<a_dimX-1 ; X++){
		for (int Y = 0 ; Y<a_dimY-1 ; Y++){
			// Components of the electric field
			md_field = array.getV(X+1,Y) - V_TempMesh.getV(X,Y);
			EF_dxMesh.setV(md_field,X,Y);
			md_field =  array.getV(X,Y+1) - V_TempMesh.getV(X,Y); 
			EF_dyMesh.setV(md_field,X,Y);
			
			// Magnitude of E	
			//md_field = sqrt(pow(EF_dxMesh.getV(X,Y),2) + pow(EF_dyMesh.getV(X,Y),2));
			//use magnitude 1 to get normal arrow sizes
			md_field = 1;
			EF_Mesh.setV(md_field,X,Y);
		}
	}
}

//**************************************//	
//	Calculates the error for the ORM	//
//**************************************//
double Algorithm::calcError(Mesh& potential, Mesh& temp){

	//largest difference value
	double difference;
	md_error=0;
	for (int X = 0 ; X<a_dimX-1 ; X++){
		for (int Y = 0 ; Y<a_dimY-1 ; Y++){
			difference = fabs(potential.getV(X,Y) - temp.getV(X,Y));
			//find the largest difference value
			if (md_error < difference){
				md_error = difference;
			}
		}
	}
	//finds the number of iterations at the end
	counter++;
	return md_error;
}

//******************************************//	
//	Calculates the over-relaxation parameter//
//******************************************//
double Algorithm::ORP(){
	double T=cos(PI/a_dimX) + cos(PI/a_dimY);
	md_orp = ( (8-sqrt(64-16*pow(T,2))) / pow(T,2));
	return md_orp;
}




Algorithm::~Algorithm(){}
