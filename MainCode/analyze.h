//class to analyze the algorithm

#ifndef Analyze_H
#define Analyze_H

#include "topalg.h"
#include "analytical.h"

class Analyze: public TopAlg{
 public:
    void compMaxRatio(double, double, double); //compares the accuracy with increasing dimension size
    void compareIterations(double, double, double);//shows the number of iterations with increasing dimensions
    void compTol(double, double, double);//compares the tolerance with the number of iterations
};

#endif
