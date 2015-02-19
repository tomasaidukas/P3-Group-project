#ifndef TEST1_H
#define TEST1_H

#include "topalg.h"

using namespace cimg_library;

class Numerical: public TopAlg{
 private:
  CImg<unsigned char> image;
  int _imagex, _imagey;
  int _scale;

  
  public:
  Numerical(double,double,double,double, std::string, int scale); //constructor
  ~Numerical(); //destructor
	
  void setBoundary(); //sets the boundaries from an image file
  };
  
  #endif
