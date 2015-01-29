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



//OUTPUT MESH
//friend function to overload << operator
//e.g. cout << mymesh
//loops over valeus of mesh and outputs them
std::ostream& operator<<(std::ostream &os_out, Mesh &thismesh)
{
  for (int i=0; i<thismesh.mn_dimX; i++){
    for (int j=0; j<thismesh.mn_dimY; j++){
      os_out << thismesh.matrix[i][j].V << " ";
    }
    os_out << std::endl;
  }
}


//INPUT MESH
//friend function to overload >> operator
//e.g. cin >> mymesh
//loops over values of mesh to input them
std::istream& operator>>(std::istream &os_in, Mesh &thismesh)
{
std::cout << "Enter values for a " << thismesh.mn_dimX << "x" << thismesh.mn_dimY << " matrix." << std::endl;
  for (int i=0; i<thismesh.mn_dimX; i++){
    for (int j=0; j<thismesh.mn_dimY; j++){
      os_in >>  thismesh.matrix[i][j].V;
    }
  }
}
