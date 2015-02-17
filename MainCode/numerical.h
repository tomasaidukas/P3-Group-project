#ifndef TEST1_H
#define TEST1_H

#include "topalg.h"

using namespace cimg_library;

class Numerical: public TopAlg{
 private:
  CImg<unsigned char> image;

  
  public:
  Numerical(double,double,double,double, std::string); //constructor
  ~Numerical(); //destructor
	
  void setBoundary(); //sets the boundaries from an image file
  };
  
  #endif
