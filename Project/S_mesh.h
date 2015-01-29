//Contains the class which defines the mesh (2D array)
//
//REQUIRED:
//Constructor code
//Destructor code
//Print potential to text file


#ifndef MESH_H
#define MESH_H

#include<iostream>



//This defines a new type which contains the electric potential
//and whether or not the point is a boundary condition.
//An array of these points will make up the mesh.
typedef struct{
  double potential;
  bool isBoundary;
}meshpoint;



class Mesh{
 private:
  meshpoint **matrix;     //array of meshpoints
  int mn_dimX, mn_dimY;    //dimensions of array
 
 public:
  Mesh(int, int);     //constructor
  ~Mesh();     //destructor
};


#endif
