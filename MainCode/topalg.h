//Abstract algoithm class
//all other algorithm classes are derived from this class

#ifndef ABST_H
#define ABST_H

#include "mesh.h"
#include<cmath>
#include<iostream>
#include<fstream>

class TopAlg{
 protected:
  int _dimx, _dimy;
  Mesh _PMesh;

  //private member functions
  virtual void setBoundary();

 public:
  TopAlg();
  ~TopAlg();
  
  void difference(TopAlg& other);
  virtual void runAlgorithm();
  virtual void printSolution();
  

};

#endif
