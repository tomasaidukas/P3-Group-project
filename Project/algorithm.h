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
#include"mesh.h"

class Algorithm{
 private:
//  Mesh V_Mesh, V_TempMesh;    //Mesh 
	double pot; // Temporary storage variable for potential
 public:
  Algorithm(double, double, double);     //constructor
  ~Algorithm();    //destructor

};




#endif
