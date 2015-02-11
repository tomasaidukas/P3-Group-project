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
  _orp = TopAlg::ORP();
  //counter to see total number of iterations
  _iter = 0;
  
  _SMesh = _PMesh;
}


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
 	TopAlg::setEdges(i,j);
    }
  }

  //	Over-relaxation algorithm
  // While the error is bigger than the tolerated one
  // carry on with approximating the solution further
  // until it is reached.
  TopAlg::calcError();
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
		TopAlg::setEdges(i,j);
      }
    }
    TopAlg::calcError();
    // Set old potential = new potential
    _PMesh = _SMesh;
  }
}

Algorithm::~Algorithm(){}
