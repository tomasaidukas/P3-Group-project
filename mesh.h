//Class to define mesh 
//
//


#ifndef MESH_H
#define MESH_H

#include<iostream>

class Mesh{
 private:
  double **matrix;    //2D array
  int mn_dimX, mn_dimY;     //x and y dimensions of array
 public:
  Mesh(int, int);     //constructor
  ~Mesh();            //destructor

  //functions to input to the matrix and output the matrix to screen
  friend std::istream& operator>> (std::istream&, const Mesh&);
  friend std::ostream& operator<< (std::ostream&, const Mesh&);
}; 

#endif
