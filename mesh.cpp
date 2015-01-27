#include "mesh.h"

//CONSTRUCTOR
//arguments - dimensions of matrix
//allocates memory to matrix[x][y]
Mesh::Mesh(int n_x, int n_y):mn_dimX(n_x),
			     mn_dimY(n_y){
  matrix = new double*[mn_dimX];
  for (int i=0; i<mn_dimX; i++){
    matrix[i] = new double[mn_dimY];
  }
}

//DESTRUCTOR
//deallocates memory from the matrix
Mesh::~Mesh(){
  for (int i=0; i<mn_dimX; i++){
    delete[] matrix[i];
  }
  delete[] matrix;
}



//INPUT STREAM OVERLOAD
//allows user to enter values to the matrix
//e.g. "std::cin >> mymesh"
std::istream& operator>> (std::istream& os_in, const Mesh& mesh){
  for (int i=0; i<mesh.mn_dimX; i++){
    for (int j=0; j<mesh.mn_dimY; j++){
      os_in >> mesh.matrix[i][j];
    }
  }
}


//OUTPUT STREAM OVERLOAD
//prints matrix to screen
std::ostream& operator<< (std::ostream& os_out, const Mesh& mesh){
  for (int i=0; i<mesh.mn_dimX; i++){
    for (int j=0; j<mesh.mn_dimY; j++){
      os_out << mesh.matrix[i][j] << " "; 
    }
    os_out << std::endl;
  }
}
