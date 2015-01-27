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


class Algorithm{
 private:
  Mesh V_mesh;    //Mesh 
 public:
  Algorithm();     //constructor
  ~Algorithm();    //destructor

};



#endif
