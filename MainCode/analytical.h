//class to define analytical algorithm

#ifndef ANALYTIC_H
#define ANALYTIC_H

#include "topalg.h"

class Analytic : public TopAlg{
 private:
  void setBoundary();

 public:
  Analytic();
  ~Analytic();
  
  void runAlgorithm();
  void printSolution();
};

#endif
