//class to define analytical algorithm

#ifndef ANALYTIC_H
#define ANALYTIC_H

#include "topalg.h"

class Analytic : public TopAlg{
 private:
  int _radius;  //radius of cylinder
  double _V;   //potential between plates
  double _L; //distance between plates
  double r;//temporary variable


 public:
  Analytic();
  Analytic(int, int, double, double, double); //constructor
  ~Analytic(); //destructor
  
  void setBoundary();
  void runAnalytical();

};

#endif
