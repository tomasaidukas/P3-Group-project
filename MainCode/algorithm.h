#ifndef TEST1_H
#define TEST1_H


#include <iostream>
#include <fstream>
#include <cmath>
#include "mesh.h"
#include "topalg.h"
#include "CImg.h"
#include <cstring>
#define PI  3.141592
using namespace cimg_library;

class Algorithm: public TopAlg{
 private:
  Mesh _SMesh; //Secondary Mesh
  double _maxV; //maximum potential
  double _err; //eror
  double _tol; //maximum error tolerance
  double _orp; //over-relaxaion parameter
  int _iter; //counts the number of iterations taken
  CImg<unsigned char> image;

  //private member functions
  void setBoundary(); //sets the boundaries from an image file OR a circle in the middle
  void setEdges(int,int);	//makes edges equal to the neighbour values
  double calcError(); //calculates md_error
  double ORP(); //calculates over-relaxation parameter

  
  public:
  Algorithm(double,double, std::string);     //constructor
  ~Algorithm();    //destructor

  void runAlgorithm(); //runs the main algorithm
  void printSolution(); //prints mesh
  };
  
  #endif
