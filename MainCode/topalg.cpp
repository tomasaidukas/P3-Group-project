#include "topalg.h"

TopAlg::TopAlg():_dimx(0),
		 _dimy(0),
		 _orp(0),
		 _err(0),
		 _tol(0)
{}

TopAlg::~TopAlg(){}

void TopAlg::setBoundary(){}

void TopAlg::runAlgorithm(){}

void TopAlg::runNumerical(){}

// Draws images:
// 1 => analytical
// 2 => numerical with circle inside
// 3 => numerical from an image
void TopAlg::printSolution(int i)
{
	if ( i == 1){
	  std::ofstream file;
	  file.open("analytical.txt");
	  file << _PMesh;
	  file.close();
	}else if ( i == 2){
	   std::ofstream file;
	  file.open("numCircle.txt");
	  file << _PMesh;
	  file.close();
	}else if ( i == 3){
	  std::ofstream file;
	  file.open("numerical.txt");
	  file << _PMesh;
	  file.close();
	}
	  
}

//takes the difference between the two plots
void TopAlg::difference(TopAlg& other)
{
  if (_dimx != other._dimx || _dimy != other._dimy){ 
    std::cout << "array size mismatch\n";
  }

  
  Mesh diffmesh = Mesh(_dimx, _dimy);
  for (int i=0; i<_dimx; i++){
    for (int j=0; j<_dimy; j++){
      double diff = fabs( _PMesh.getV(i,j) - other._PMesh.getV(i,j) );
      diffmesh.setV(diff,i,j);
    }
  }

  std::ofstream file;
  file.open("difference.txt");
  file << diffmesh;
  file.close();
  
}

//takes the ratio between the two plots
void TopAlg::ratio(TopAlg& other)
{
  if (_dimx != other._dimx || _dimy != other._dimy){ 
    std::cout << "array size mismatch\n";
  }

  
  Mesh diffmesh = Mesh(_dimx, _dimy);
  for (int i=0; i<_dimx; i++){
    for (int j=0; j<_dimy; j++){
    	if (!other._PMesh.getisBoundary(i,j)){
	      double diff = fabs(_PMesh.getV(i,j) / other._PMesh.getV(i,j));
  	    diffmesh.setV(diff,i,j);
  	  }
    }
  }

  std::ofstream file;
  file.open("ratio.txt");
  file << diffmesh;
  file.close();
  
}


//**************************************//	
//	Calculates the error for the ORM	//
//**************************************//
double TopAlg::calcError(){

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
double TopAlg::ORP(){
	double T=cos(PI/_dimx) + cos(PI/_dimy);
	_orp = ( (8-sqrt(64-16*pow(T,2))) / pow(T,2));
	return _orp;
}


//SET EDGES TO MAKE IT SIMILAR TO THE ANALYTICAL CASE
void TopAlg::setEdges(int i,int j)
{
			// Check whether the boundaries of the mesh have a plate or not
			// if they have a plate, then leave it alone. If not,
			// set it equal to the neighbourh value in order to eliminate
			// the zeros. This is for all four boundaries
			
			//j and i go from 1 to dim-2 in the main algorithm
			//we want them to go from 0 to dim-1
			//hence, we add 0 and dim-1 separately
				double tempvalue;
				
				
				// THE EDGE AT X=0 THROUGH ALL Y VALUES
				if ( !_SMesh.getisBoundary(0,j) ){
					tempvalue = _SMesh.getV(1,j);
					_SMesh.setV(tempvalue,0,j);}
				
				if ( !_SMesh.getisBoundary(0,0) ){
	 				tempvalue = _SMesh.getV(1,0);
					_SMesh.setV(tempvalue,0,0);
				}
				if ( !_SMesh.getisBoundary(0,_dimy-1) ){
	 				tempvalue = _SMesh.getV(1,_dimy-1);
					_SMesh.setV(tempvalue,0,_dimy-1);
				}
				
				
				// THE EDGE AT X=_dimx-1 THROUGH ALL Y VALUES
				if ( !_SMesh.getisBoundary(_dimx-1,j) ){				
					 tempvalue = _SMesh.getV(_dimx-2,j);
					_SMesh.setV(tempvalue,_dimx-1,j);
				}
				//ADD THE ENDS
				if ( !_SMesh.getisBoundary(_dimx-1,0) ){				
	 				tempvalue = _SMesh.getV(_dimx-2,0);
					_SMesh.setV(tempvalue,_dimx-1,0);
				}
				if ( !_SMesh.getisBoundary(_dimx-1,_dimy-1) ){				
	 				tempvalue = _SMesh.getV(_dimx-2,_dimy-1);
					_SMesh.setV(tempvalue,_dimx-1,_dimy-1);
				}
				
				
				
				// THE EDGE AT Y=0 THROUGH ALL X VALUES
				if ( !_SMesh.getisBoundary(i,0) ){						
					 tempvalue = _SMesh.getV(i,1);
					_SMesh.setV(tempvalue,i,0);
				}
				//ADD THE ENDS
				if ( !_SMesh.getisBoundary(0,0) ){			
	 				tempvalue = _SMesh.getV(0,1);
					_SMesh.setV(tempvalue,0,0);
				}
				if ( !_SMesh.getisBoundary(_dimx-1,0) ){			
	 				tempvalue = _SMesh.getV(_dimx-1,1);
					_SMesh.setV(tempvalue,_dimx-1,0);
				}
				
				// THE EDGE AT Y=_dimy-1 THROUGH ALL X VALUES
				if ( !_SMesh.getisBoundary(i,_dimy-1) ){						
					 tempvalue = _SMesh.getV(i,_dimy-2);
					_SMesh.setV(tempvalue,i,_dimy-1);
				}
				//ADD THE ENDS
				if ( !_SMesh.getisBoundary(0,_dimy-1) ){
	 				tempvalue = _SMesh.getV(0,_dimy-2);
					_SMesh.setV(tempvalue,0,_dimy-1);
				}
				if ( !_SMesh.getisBoundary(_dimx-1,_dimy-1) ){
	 				tempvalue = _SMesh.getV(_dimx-1,_dimy-2);
					_SMesh.setV(tempvalue,_dimx-1,_dimy-1);
				}
}	


