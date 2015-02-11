#ifndef TEST1_H
#define TEST1_H

#include "topalg.h"

using namespace cimg_library;

class Algorithm: public TopAlg{
 private:
  double _maxV; //maximum potential
  double _tol; //neded for input
  int _iter; //counts the number of iterations taken
  CImg<unsigned char> image;
  
  public:
  Algorithm(double,double, std::string);     //constructor
  ~Algorithm();    //destructor
	
  void setBoundary(); //sets the boundaries from an image file OR a circle in the middle
  void runAlgorithm(); //runs the main algorithm

  };
  
  #endif
