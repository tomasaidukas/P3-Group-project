//Contains the class which defines the mesh (2D array)
//
//REQUIRED:
//Constructor code
//Destructor code
//Print potential to text file


#ifndef MESH_H
#define MESH_H

#include<iostream>
#include<fstream>
#include<cmath>


//This defines a new type which contains the electric potential
//and whether or not the point is a boundary condition.
//An array of these points will make up the mesh.
typedef struct{
  double V;
}meshpoint;



class Mesh{
 private:
  meshpoint **matrix;     //array of meshpoints
  int mn_dimX, mn_dimY;    //dimensions of array
 
public:
  Mesh();			//default constructor
  Mesh(int, int);     //constructor
  Mesh(const Mesh&); //copy constructor
  ~Mesh();     //destructor

  //mutator functions
  void setV(double, int, int);
  void Allocate(int, int);
  void setAllZero(); //set all array values to 0
  void setEqual(Mesh&); //makes the arrays equal
  Mesh& operator=(const Mesh&); //assignment operator

  //accesssor functions
  void FieldData(Mesh& dx, Mesh& dy); //outputs field to a file
  void PotentialData(); //outputs potential to a file
  double getV(int, int);
  int getDimX();
  int getDimY();
};


#endif