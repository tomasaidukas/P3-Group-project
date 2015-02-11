//Contains the class which defines the mesh (2D array)
//
//REQUIRED:
//Constructor code
//Destructor code
//Print potential to text file


#ifndef MESH_H
#define MESH_H

#include"topalg.h"

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
  Mesh();			//default constructor
  Mesh(int, int);     //constructor
  Mesh(const Mesh&); //copy constructor
  ~Mesh();     //destructor

  //mutator functions
  void setV(double, int, int);
  void setisBoundary(bool, int, int);
  void setAllZero(); //set all array values to 0
  Mesh& operator=(const Mesh&); //assignment operator

  //accesssor functions
  double getV(int, int);
  bool getisBoundary(int, int);
  int getDimX();
  int getDimY();

  //friend functions
  friend std::ostream& operator<<(std::ostream& out, const Mesh& mesh);
};


#endif
