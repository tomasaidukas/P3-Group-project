//Contains the function definitions for the Mesh class


#include "S_mesh.h"

//CONSTRUCTOR
//Allocates memory to the 2D array of meshpoints
<<<<<<< HEAD
Mesh::Mesh(int n_dimX, int n_dimY): mn_dimX(n_dimX),
				    mn_dimY(n_dimY)
=======
Mesh::Mesh(int n_dimX, int n_dimY):mn_dimX(n_dimX),
				   mn_dimY(n_dimY)
>>>>>>> c3b1f2ef37be591568add41bd7b17e4d2dd20ccf
{
  //allocate memory for x array
  matrix = new meshpoint*[mn_dimX];

<<<<<<< HEAD
  //allocate memory for y array
=======
  //allocate memory for y arrays
>>>>>>> c3b1f2ef37be591568add41bd7b17e4d2dd20ccf
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
<<<<<<< HEAD
  delete[] matrix[];
=======
  delete[] matrix;
>>>>>>> c3b1f2ef37be591568add41bd7b17e4d2dd20ccf
}
