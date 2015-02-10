#include "algorithm.h"


//**************************************//	
//	 		CONSTRUCTOR 				//
//**************************************//
Algorithm::Algorithm(double tol, double maxV, std::string str): TopAlg(),
								_tol(tol),
								_maxV(maxV)
{
  //load the image
  image.load(str.c_str());
  
  //image dimensions
  _dimx = image.height();  
  _dimy = image.width();
  
  //allocate dimensions to new arrays
  _PMesh = Mesh(_dimx, _dimy);
  _SMesh = Mesh(_dimx, _dimy);

  //set all values to zero initialy
  _PMesh.setAllZero();
  _SMesh.setAllZero();
  
  //set the boundaries  
  setBoundary();
  
  //calculate the over-relaxation parameter
  //which depends on the array size
  ORP();
  
  //counter to see total number of iterations
  _iter = 0;
  
  _SMesh = _PMesh;
}


//**************************************//	
// 		Set the boundaries				//
//**************************************//
void Algorithm::setBoundary()
{
  // set the boundaries from an image file
	for (int y=0 ; y<_dimx ; y++){
		for (int x=0 ; x<_dimy ; x++){
			if( ((int) image(x,y,0,0) == 255) && ((int)image(x,y,0,1)==0) && ((int)image(x,y,0,2) == 0) ){
				_PMesh.setV(_maxV,x,y);
				_PMesh.setisBoundary(true, x, y);
				_SMesh.setV(_maxV,x,y);
				_SMesh.setisBoundary(true, x, y);
			}else if( ((int) image(x,y,0,0) == 0) && ((int)image(x,y,0,1)==255) && ((int)image(x,y,0,2) == 0) ){
				_PMesh.setV(0,x,y); 
				_PMesh.setisBoundary(true, x, y);
				_SMesh.setV(0,x,y);
				_SMesh.setisBoundary(true, x, y);
			}else if( ((int) image(x,y,0,0) == 0) && ((int)image(x,y,0,1)==0) && ((int)image(x,y,0,2) == 255) ){
				_PMesh.setV(_maxV-2*_maxV,x,y);
				_PMesh.setisBoundary(true, x, y);
				_SMesh.setV(_maxV-2*_maxV,x,y);
				_SMesh.setisBoundary(true, x, y);
			}
		}
	}
 }




//**************************************//	
// 		Executes the algorithm			//
//**************************************//
void Algorithm::runAlgorithm(){
	double tempvalue;
  // 		Solution one iteration ahead
  //	 	using the Jacobi method	
  for (int i = 1 ; i<_dimx-1 ; i++){
    for (int j = 1 ; j<_dimy-1 ; j++){
      if (!_PMesh.getisBoundary(i,j)){
			double tempvalue = (_PMesh.getV(i+1,j) + 
			    _PMesh.getV(i-1,j) + 
			    _PMesh.getV(i,j+1) + 
			    _PMesh.getV(i,j-1))/4;
			_SMesh.setV(tempvalue,i,j);
      }
      setEdges(i,j);
    }
  }

  //	Over-relaxation algorithm
  // While the error is bigger than the tolerated one
  // carry on with approximating the solution further
  // until it is reached.
  calcError();
  //calculate the error between two meshes
  while (_err > _tol){
    //main algorithm
    for (int i = 1 ; i<_dimx-1 ; i++){
      for (int j = 1 ; j<_dimy-1 ; j++){
		if (!_SMesh.getisBoundary(i,j)){
		  double tempvalue = ((1-_orp)*_PMesh.getV(i,j) + 
					  (_orp/4)*(_PMesh.getV(i+1,j) + 
						_SMesh.getV(i-1,j) + 
						_PMesh.getV(i,j+1) + 
						_SMesh.getV(i,j-1)));
		  _SMesh.setV(tempvalue,i,j);
		}
		//set edges eql to neighbour
		setEdges(i,j);	
      }
    }
    calcError();
    // Set old potential = new potential
    _PMesh = _SMesh;
  }
}




//**************************************//	
//	Calculates the error for the ORM	//
//**************************************//
double Algorithm::calcError(){

	//largest difference value
	double difference;
	_err=0;
	for (int X = 0 ; X<_dimx ; X++){
		for (int Y = 0 ; Y<_dimy ; Y++){
			difference = fabs(_SMesh.getV(X,Y) - _PMesh.getV(X,Y));
			//find the largest difference value
			if (_err < difference){
				_err = difference;
			}
		}
	}
	//finds the number of iterations at the end
	_iter++;
	return _err;
}

//******************************************//	
//	Calculates the over-relaxation parameter//
//******************************************//
double Algorithm::ORP(){
	double T=cos(PI/_dimx) + cos(PI/_dimy);
	_orp = ( (8-sqrt(64-16*pow(T,2))) / pow(T,2));
	return _orp;
}



//PRINT SOLUTIONS
void Algorithm::printSolution()
{
  std::ofstream file;
  file.open("numerical.txt");
  file << _PMesh; //print mesh to file
  file.close();
}

//SET EDGES TO MAKE IT SIMILAR TO THE ANALYTICAL CASE
void Algorithm::setEdges(int i,int j)
{
			// Check whether the boundaries of the mesh have a plate or not
			// if they have a plate, then leave it alone. If not,
			// set it equal to the neighbourh value in order to eliminate
			// the zeros. This is for all four boundaries
			
			double tempvalue = _SMesh.getV(1,j-1);
				_SMesh.setV(tempvalue,0,j-1);
				//end value
 				tempvalue = _SMesh.getV(1,_dimy-1);
				_SMesh.setV(tempvalue,0,_dimy-1);
				
				 tempvalue = _SMesh.getV(_dimx-2,j-1);
				_SMesh.setV(tempvalue,_dimx-1,j-1);
				//end value
 				tempvalue = _SMesh.getV(_dimx-2,_dimy-1);
				_SMesh.setV(tempvalue,_dimx-1,_dimy-1);
				
				 tempvalue = _SMesh.getV(i-1,1);
				_SMesh.setV(tempvalue,i-1,0);
				//end value
 				tempvalue = _SMesh.getV(_dimx-1,1);
				_SMesh.setV(tempvalue,_dimx-1,0);
						
				 tempvalue = _SMesh.getV(i-1,_dimy-2);
				_SMesh.setV(tempvalue,i-1,_dimy-1);
				//end value
 				tempvalue = _SMesh.getV(_dimx-1,_dimy-2);
				_SMesh.setV(tempvalue,_dimx-1,_dimy-1);
}




Algorithm::~Algorithm(){}
