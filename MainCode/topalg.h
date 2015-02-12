//Abstract algoithm class
//all other algorithm classes are derived from this class

#ifndef ABST_H
#define ABST_H

#include<cmath>
#include<iostream>
#include<fstream>
#include "mesh.h"
#include "CImg.h"
#include <cstring>
#define PI 3.141592

class TopAlg{
 protected:
  int _dimx, _dimy;
  Mesh _PMesh;
  Mesh _SMesh;
  double _orp;
  double _tol;
  double _err;
  double _iter;
  
  //private member functions
  virtual void setBoundary();

 public:
  TopAlg();
  ~TopAlg();
  
  void difference(TopAlg& other);
  virtual void runAlgorithm();
  virtual void runNumerical();
  virtual void setEdges(int,int);
  virtual double calcError();
  virtual double ORP();
  virtual void printSolution(int);
};

#endif
