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
  double V;
  bool isBoundary;
}meshpoint;



class Mesh{
 private:
  meshpoint **matrix;     //array of meshpoints
  int mn_dimX, mn_dimY;    //dimensions of array
<<<<<<< HEAD
  
=======
 
>>>>>>> c3b1f2ef37be591568add41bd7b17e4d2dd20ccf
 public:
  Mesh(int, int);     //constructor
  ~Mesh();     //destructor
};


#endif
