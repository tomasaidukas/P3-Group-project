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
  file.open("solution.txt");
  file << _PMesh;
  file.close();
}

