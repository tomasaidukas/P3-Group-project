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
  double _err;
  double _tol;
  double _maxV;
  double _iter;
  

 public:
  TopAlg();
  ~TopAlg();

  
  void difference(TopAlg& other);
  void ratio(TopAlg& other);
  double runAlgorithm();
  virtual void setEdges(int,int);
  virtual double calcError();
  virtual double ORP();
  virtual void printSolution(int);
   
};

#endif
