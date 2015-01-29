//Contains the function definitions for the Mesh class


#include "mesh.h"

//CONSTRUCTOR
//Allocates memory to the 2D array of meshpoints
Mesh::Mesh(int n_dimX, int n_dimY): mn_dimX(n_dimX),
				    mn_dimY(n_dimY)
{
  //allocate memory for x array
  matrix = new meshpoint*[mn_dimX];

  //allocate memory for y arrays
  for (int i=0; i<mn_dimX; i++){
    matrix[i] = new meshpoint[mn_dimY];
  }
}

//DESTRUCTOR
//Deallocates memory from the 2D array of meshpoints
Mesh::~Mesh()
{
  //deallocate y arrays
  for (int i=0; i<mn_dimX; i++){
    delete[] matrix[i];
  }

  //deallocate x array
  delete[] matrix;
}
