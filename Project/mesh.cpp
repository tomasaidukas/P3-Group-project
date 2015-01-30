//Contains the function definitions for the Mesh class


#include "mesh.h"

Mesh::Mesh(){

}

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

//COPY CONSTRUCTOR
//reproduces mesh taken as argument
//e.g. Mesh(oldmesh)
Mesh::Mesh(const Mesh& tempmesh): mn_dimX(tempmesh.mn_dimX),
				    mn_dimY(tempmesh.mn_dimY)
{
  //allocate memory for x array
  matrix = new meshpoint*[mn_dimX];

  //allocate memory for y arrays
  for (int i=0; i<mn_dimX; i++){
    matrix[i] = new meshpoint[mn_dimY];
   }
  //copy values 
  for (int i=0; i<mn_dimX; i++ ){
  	 for (int j=0; j<mn_dimY; j++ ){
  		matrix[i][j] = tempmesh.matrix[i][j];
  	}
  }
}

//ASSIGNMENT OPERATOR OVERLOAD
//sets meshes equal to each other
//e.g. mesh1 = mesh2
Mesh & Mesh::operator=(const Mesh& rhs)
{
  if (this == &rhs) { return *this; } //if meshes are equal return out
  
  //deallocate matrix memory
  for (int i=0; i<mn_dimX; i++){
    delete[] matrix[i];
  }
  delete[] matrix;
  
  //copy new private member variables 
  mn_dimX = rhs.mn_dimX;
  mn_dimY = rhs.mn_dimY;
  
  //allocate new matrix memory
  matrix = new meshpoint*[mn_dimX];
  for (int i=0; i<mn_dimX; i++){
    matrix[i] = new meshpoint[mn_dimY];
  }

  //copy matrix values over
  for (int i=0; i<mn_dimX; i++){
    for (int j=0; j<mn_dimY; j++){
      matrix[i][j] = rhs.matrix[i][j];
    }
  }
  return *this;
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

void Mesh::setEqual(Mesh& tempmesh){
	for (int X = 1 ; X<mn_dimX-1 ; X++){
		for (int Y = 1 ; Y<mn_dimY-1 ; Y++){
			matrix[X][Y].V = tempmesh.matrix[X][Y].V;	
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

void Mesh::PotentialData(){
	
	std::ofstream potentialData;
	potentialData.open ("Potential_Values.txt");
	
	potentialData << "X " << "Y " << "V " << std::endl;
	for (int X = 0 ; X<mn_dimX ; X++){
		for (int Y = 0 ; Y<mn_dimY ; Y++){
			potentialData << X << " " << Y << " " << matrix[X][Y].V << std::endl ;
			
		}
	}
	
	potentialData.close();
}


void Mesh::FieldData(Mesh& dx, Mesh& dy){
	
	std::ofstream fieldData;
	fieldData.open ("Field_Values.txt");

	fieldData << "X " << "Y " << "|E| " << "dxE " << "dyE " << std::endl;
	for (int X = 0 ; X<mn_dimX ; X++){
		for (int Y = 0 ; Y<mn_dimY ; Y++){
			fieldData << X << " " << Y << " " << matrix[X][Y].V << " " << dx.matrix[X][Y].V << " " << dy.matrix[X][Y].V  << std::endl ;
			
		}
	}
	
	fieldData.close();
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
