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
#include <time.h> //compare computation time

#define PI 3.141592

class TopAlg{
 public:
  int _dimx, _dimy;
  Mesh _PMesh;
  Mesh _SMesh;
  Mesh _EMesh;
  Mesh _EdxMesh;
  Mesh _EdyMesh;
  double _orp;
  double _err;
  double _tol;
  double _maxV1;
  double _maxV2;
  double _maxV3;
  double _iter;
  double _time;
  double _maxError;

 public:
  TopAlg();
  ~TopAlg();
  
  double maxDiff(TopAlg& other);
  double getTolerance();
  double getTime();
  double getIter();
  void difference(TopAlg& other);
  void ratio(TopAlg& other);
  void runAlgorithm();
  void runElectric(int);
  virtual void setEdges(int,int);
  virtual double calcError();
  virtual double ORP();
  virtual void printPotential(int);
   
};

#endif
