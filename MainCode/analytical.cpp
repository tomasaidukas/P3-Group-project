#include "analytical.h"



/*************************************************
 * Constructor
 * Takes dimensions of X and Y, radius of the
 * circle in the middle, its potential and
 * an error tolerance as arguments
 *************************************************/
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




/*************************************************
 * Sets boundary conditions for the numerical
 * case where a circle is in the middle
 * in an electrostatic field
 *************************************************/
void Analytic::setBoundary()
{
    double r;
    //insert the parallel plates
    //this sets the plates on the y axis
    for (int j = 0 ; j<_dimy ; j++){
	_PMesh.setV(_V/2,0,j);
	_SMesh.setV(_V/2,0,j);
	_PMesh.setisBoundary(true,0,j);
	_SMesh.setisBoundary(true,0,j);
	_PMesh.setV(-_V/2,_dimx-1,j);
	_SMesh.setV(-_V/2,_dimx-1,j);		
	_PMesh.setisBoundary(true,_dimx-1,j);
	_SMesh.setisBoundary(true,_dimx-1,j);
    }
	
	
    //insert a circle in the middle
    for (int i = 0 ; i<_dimx ; i++){
	for (int j = 0 ; j<_dimy ; j++){
	    r = sqrt(pow(i-_dimx/2,2) + pow(j-_dimy/2,2));
		if (pow(r,2)<=pow(_radius,2)){
		    _PMesh.setisBoundary(true,i,j);
  		    _SMesh.setisBoundary(true,i,j);
  		   }
  	  }
   }
}


/*************************************************
 * Runs the algorithm to find the analytical
 * solution
 *************************************************/
void Analytic::runAnalytical()
{
    double r;
    double _E0 = _V/_dimx;
    double costheta;
    double tempval;
    
    for (int i=0; i<_dimx; i++){
	for (int j=0; j<_dimy; j++){
	    r = sqrt(pow(i-_dimx/2,2) + pow(j-_dimy/2,2));
	    if (pow(r,2)>pow(_radius,2)){
 		costheta = (i-_dimx/2)/r;	
 		tempval = (-_E0 * ( r - (pow(_radius,2)/r)) * costheta);
		 _PMesh.setV(tempval, i, j);
	    }
	}	 
    }
}

//destructor
Analytic::~Analytic(){}
