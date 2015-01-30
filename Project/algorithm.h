//Contains class which performs algorithm.
//
//REQUIRES:
//Constructor Code
//     -constructor should take shape as argument and assign boundary conditions
//Destructor Code
//Analytical Method subclass
//Numerical Method subclass


#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <fstream>
#include "mesh.h"

class Algorithm{
 private:
  int mn_dimX, mn_dimY;//dimensions of mesh
  Mesh V_Mesh;//Primary Mesh
  Mesh V_TempMesh;//Secondary Mesh
  double md_pot; // Temporary storage variable for potential
  double md_field; // Temporary storage variable for el. field
  double md_orp; //over-relaxation parameter
  double md_error;
  double md_tolerance;//error tolerance

  //private member functions
  void setBoundary();

 public:
  Algorithm(double, double, double);     //constructor
  ~Algorithm();    //destructor

  void runAlgorithm();//runs the algorithm
};




#endif
