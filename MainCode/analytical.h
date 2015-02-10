//class to define analytical algorithm

#ifndef ANALYTIC_H
#define ANALYTIC_H

#include "topalg.h"
#include<math.h>
#include<iostream>

class Analytic : public TopAlg{
 private:
  int _radius;  //radius of cylinder
  double _E0;   //E0

  void setBoundary();

 public:
  Analytic();
  Analytic(int dimx, int dimy);
  ~Analytic();
  
  void runAlgorithm();
  // void printSolution();
};

#endif
