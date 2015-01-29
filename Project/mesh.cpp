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

// copy constructor
Mesh::Mesh(const Mesh& tempmesh): mn_dimX(tempmesh.mn_dimX),
				    mn_dimY(tempmesh.mn_dimY)
{
	//allocate memory for x array
  matrix = new meshpoint*[mn_dimX];

  //allocate memory for y arrays
  for (int i=0; i<mn_dimX; i++){
    matrix[i] = new meshpoint[mn_dimY];
   }
   
  for (int x=0; x<mn_dimX; x++ ){
  	 for (int y=0; y<mn_dimY; y++ ){
  		matrix[x][y] = tempmesh.matrix[x][y];
  	}
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


//MUTATOR FUNCTIONS
void Mesh::setV(double d_V, int i, int j)
{
  matrix[i][j].V = d_V;
}

void Mesh::setisBoundary(bool b_cond, int i, int j)
{
  matrix[i][j].isBoundary = b_cond;
}

void Mesh::setAllZero(){
	for (int X = 0 ; X<mn_dimX ; X++){
		for (int Y = 0 ; Y<mn_dimY ; Y++){	
			matrix[X][Y].V = 0;
		}
	}
	
}

//ACCESSOR FUNCTIONS
double Mesh::getV(int i, int j)
{
  return matrix[i][j].V;
}

bool Mesh::getisBoundary(int i, int j)
{
  return matrix[i][j].isBoundary;
}

int Mesh::getDimX(){
	return mn_dimX;
}

int Mesh::getDimY(){
	return mn_dimY;
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
