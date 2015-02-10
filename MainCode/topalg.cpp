#include "topalg.h"

TopAlg::TopAlg():_dimx(0),
		 _dimy(0)
{}

TopAlg::~TopAlg(){}

void TopAlg::setBoundary(){}

void TopAlg::runAlgorithm(){}

void TopAlg::printSolution()
{
  std::ofstream file;
  file.open("Potential_Values.txt");
  file << _PMesh;
  file.close();
}



/*
BROKEN
void TopAlg::difference(TopAlg& other)
{
  if (_dimx != other._dimx || _dimy != other._dimy){ 
    std::cout << "array size mismatch\n";
    return;
  }
  
  Mesh diffmesh = Mesh(_dimx, _dimy);
  for (int i=0; i<_dimx; i++){
    for (int j=0; j<_dimy; j++){
      double diff = fabs( _PMesh.getV(i,j) - other._PMesh.getV(i,j) );
      diffmesh.setV(diff,i,j);
    }
  }

  std::ofstream file;
  file.open("diffeence.txt");
  file << diffmesh;
  file.close();
}
*/
