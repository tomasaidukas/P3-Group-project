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

#include<iostream>
#include"S_mesh.h"
#include"S_shape.h"

class Algorithm{
 private:
  Mesh V_mesh;    //Mesh 
  double orp;	  //Over-relaxation	parameter
  double error;   //Error tolerance of the algorithm
 public:
 // will skip shapes and test with an empty mesh first
 // therefore, the constructor won't take any arguments for now

  Algorithm();     //constructor
  ~Algorithm();    //destructor

};




#endif
