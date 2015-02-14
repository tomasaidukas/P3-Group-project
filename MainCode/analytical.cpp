#include "analytical.h"

//default constructor
Analytic::Analytic(): TopAlg(),
		      _radius(0){}

//overload constructor
Analytic::Analytic(int dimx, int dimy, double radius, double V, double tol)
{
  //initialize tolerance
  _tol = tol;
  //initialize radius
  _radius = radius;
  //initialize potential difference
  _V = V;
  _iter = 0;
	
  //initialize dimensions
  _dimx = dimx;
  _dimy = dimy;
  
  //distance between the plates
  _L = _dimx;
  
  //allocate memory for arrays
  _PMesh = Mesh(_dimx, _dimy);
  _SMesh = Mesh(_dimx, _dimy);
  
  //initialize the over-relaxation parameter
  _orp = TopAlg::ORP();
  
  //set arrays to zero
  _PMesh.setAllZero();
  _SMesh.setAllZero();
  
  //set boundaries
  setBoundary();
}



//set boundary conditions
void Analytic::setBoundary()
{
	double r;
	
  //insert the parallel plates
  //this sets the plates on the y axis
	for (int j = 0 ; j<_dimy ; j++){
	  _PMesh.setV(_V/2,j,0);
		_SMesh.setV(_V/2,j,0);
		_PMesh.setisBoundary(true,j,0);
		_SMesh.setisBoundary(true,j,0);
		_PMesh.setV(-_V/2,j,_dimy-1);
		_SMesh.setV(-_V/2,j,_dimy-1);		
		_PMesh.setisBoundary(true,j,_dimy-1);
		_SMesh.setisBoundary(true,j,_dimy-1);
	}
	
	
	//insert a circle in the middle
  for (int i = 0 ; i<_dimx ; i++){
  	 for (int j = 0 ; j<_dimy ; j++){
		r = sqrt(pow(i-_L/2,2) + pow(j-_L/2,2));
  		   if (pow(r,2)<=pow(_radius,2)){
  		    _PMesh.setisBoundary(true,i,j);
  		    _SMesh.setisBoundary(true,i,j);
  		   }
  	  }
   }
}

//run algorithm

void Analytic::runAnalytical()
{
	double r;
  double _E0 = _V/_L;
  for (int i=0; i<_dimx; i++){
    for (int j=0; j<_dimy; j++){
			r = sqrt(pow(i-_L/2,2) + pow(j-_L/2,2));
      if (pow(r,2)>pow(_radius,2)){
 				double costheta = (i-_L/2)/r;	
 				double tempval = (-_E0 * ( r - (pow(_radius,2)/r)) * costheta);
			 _PMesh.setV(tempval, i, j);
	  	}
   	}	 
  }
}

//destructor
Analytic::~Analytic(){}
