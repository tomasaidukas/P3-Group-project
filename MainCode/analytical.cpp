#include "analytical.h"

//default constructor
Analytic::Analytic(): TopAlg(),
		      _radius(0){}

//overload constructor
Analytic::Analytic(int dimx, int dimy): TopAlg()
{
  _dimx = dimx;
  _dimy = dimy;
  _PMesh = Mesh(_dimx, _dimy);
  _SMesh = Mesh(_dimx, _dimy);
  _orp = TopAlg::ORP();
  _tol = 0.0001;
  _PMesh.setAllZero();
  _SMesh.setAllZero();
  setBoundary();
}

//destructor
Analytic::~Analytic(){}


//set boundary conditions
void Analytic::setBoundary()
{
  std::cout << "Enter radius of circle: ";
  std::cin >> _radius;
  std::cout << "Enter the potential difference between the plates (-ve V - +ve V) ";
  std::cin >> _V;
  std::cout << "Enter the distance between the plates ";
  std::cin >> _L;


  double r;
  	// Boundary conditions for the parallel plates
	for (int j = 0 ; j<_dimy ; j++){
		_PMesh.setV(_V/2,0,j);
		_SMesh.setV(_V/2,0,j);
		_PMesh.setisBoundary(true,0,j);
		_SMesh.setisBoundary(true,0,j);
		_PMesh.setV(-_V/2,_dimy-1,j);
		_SMesh.setV(-_V/2,_dimy-1,j);		
		_PMesh.setisBoundary(true,_dimy-1,j);
		_SMesh.setisBoundary(true,_dimy-1,j);
	}
	
	//insert a circle in the middle
  	for (int i = 0 ; i<_dimx ; i++){
  	  for (int j = 0 ; j<_dimy ; j++){
			 r = pow(i-_L/2,2) + pow(j-_L/2,2);
  		    if (pow(r,2)<=pow(_radius,2)){
  		    	_PMesh.setisBoundary(true,i,j);
  		    	_SMesh.setisBoundary(true,i,j);
  		    }
  	  }
    }
	
}

//run algorithm

void Analytic::runAlgorithm()
{
  double _E0 = _V/_L;
  for (int i=0; i<_dimx; i++){
    for (int j=0; j<_dimy; j++){
      	double r = sqrt(pow(i-_L/2,2) + pow(j-_L/2,2));
				  if (r<=_radius){continue;}
			double costheta = (i-_L/2)/r;	
		  double tempval = (-_E0 *
				( r - (pow(_radius,2)/r)) * costheta);
		  _PMesh.setV(tempval, i, j);
    } 
  }
}





// calculate the numerical solution using the parameter used in the 
// analytical solution
void Analytic::runNumerical(){
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
