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
}

//run algorithm
void Analytic::runAlgorithm()
{
  double _E0 = _V/_L;
  for (int i=0; i<_dimx; i++){
    for (int j=0; j<_dimy; j++){
      if (i==0 || j==0){continue;}
      	double r = sqrt(pow(i-_radius/2,2) + pow(j-_radius/2,2));
      if (r<=_radius){continue;}
		  double costheta = (i-_radius/2)/r;
		  
		  double tempval = (-_E0 *
				( r - (pow(_radius,2)/r)) * costheta);
		  _PMesh.setV(tempval, i, j);
    }
  }

}




//print solution
//void Analytic::printSolution(){}
