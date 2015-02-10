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
  std::cout << "Enter value of E0: ";
  std::cin >> _E0;
}

//run algorithm
void Analytic::runAlgorithm()
{
  for (int i=0; i<_dimx; i++){
    for (int j=0; j<_dimy; j++){
      if (i==0 || j==0){continue;}
      double r = sqrt(pow(i-25,2) + pow(j-25,2));
      if (r<=_radius){continue;}
      double costheta = (i-25)/r;
      
      double tempval = (-_E0 *
			( r - (pow(_radius,2)/r)) * costheta);
      _PMesh.setV(tempval, i, j);
    }
  }

}

//print solution
//void Analytic::printSolution(){}
