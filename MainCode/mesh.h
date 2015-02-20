//Contains the class which defines the mesh (2D array)
#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <cmath>

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
  int _dimx, _dimy;    //dimensions of array
 
public:
  double _Spacing;//defines the spacing in the << constructor for plotting. Need to rarify the data for root to get nice plots
  Mesh(); //default constructor
  Mesh(int, int); //constructor
  Mesh(const Mesh&); //copy constructor
  ~Mesh(); //destructor
  
  void setSpacing(double);// sets the _spacing parameter
  void setV(double, int, int); //set the potential
  void setisBoundary(bool, int, int); //set boundary to be true/false
  void setAllZero(); //set all array values to 0
  Mesh& operator=(const Mesh&); //assignment operator

  double getV(int, int);
  bool getisBoundary(int, int);
  int getDimX();
  int getDimY();

  friend std::ostream& operator<<(std::ostream& out, const Mesh& mesh);
};

#endif
