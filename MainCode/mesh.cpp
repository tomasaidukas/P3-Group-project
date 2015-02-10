//Contains the function definitions for the Mesh class


#include "mesh.h"

Mesh::Mesh():_dimx(0),
	     _dimy(0),
	     matrix(0)
{}

//CONSTRUCTOR
//Allocates memory to the 2D array of meshpoints
Mesh::Mesh(int dimx, int dimy): _dimx(dimx),
				_dimy(dimy)
{
  //allocate memory for x array
  matrix = new meshpoint*[_dimx];

  //allocate memory for y arrays
  for (int i=0; i<_dimx; i++){
    matrix[i] = new meshpoint[_dimy];
  }
}

//COPY CONSTRUCTOR
//reproduces mesh taken as argument
//e.g. Mesh(oldmesh)
Mesh::Mesh(const Mesh& tempmesh): _dimx(tempmesh._dimx),
				    _dimy(tempmesh._dimy)
{
  //allocate memory for x array
  matrix = new meshpoint*[_dimx];

  //allocate memory for y arrays
  for (int i=0; i<_dimx; i++){
    matrix[i] = new meshpoint[_dimy];
   }
   
  //copy values 
  for (int i=0; i<_dimx; i++ ){
  	 for (int j=0; j<_dimy; j++ ){
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
  for (int i=0; i<_dimx; i++){
    delete[] matrix[i];
  }
  delete[] matrix;
  
  //copy new private member variables 
  _dimx = rhs._dimx;
  _dimy = rhs._dimy;
  
  //allocate new matrix memory
  matrix = new meshpoint*[_dimx];
  for (int i=0; i<_dimx; i++){
    matrix[i] = new meshpoint[_dimy];
  }

  //copy matrix values over
  for (int i=0; i<_dimx; i++){
    for (int j=0; j<_dimy; j++){
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
  for (int i=0; i<_dimx; i++){
    delete[] matrix[i];
  }
	
	std::cout << "destroying array " << std::endl;
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
	for (int X = 0 ; X<_dimx ; X++){
		for (int Y = 0 ; Y<_dimy ; Y++){	
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
	return _dimx;
}

int Mesh::getDimY(){
	return _dimy;
}

void Mesh::PotentialData(){
	
	std::ofstream potentialData;
	potentialData.open ("Potential_Values.txt");
	
	for (int X = 0 ; X<_dimx ; X++){
		potentialData << std::endl;
		for (int Y = 0 ; Y<_dimy ; Y++){
			potentialData << matrix[X][Y].V << " " ;
			
		}
	}
	
	potentialData.close();
}


void Mesh::FieldData(Mesh& dx, Mesh& dy){
	
	std::ofstream fieldData;
	fieldData.open ("Field_Values.txt");

	fieldData << "X " << "Y " << "|E| " << "dxE " << "dyE " << std::endl;
	for (int X = 0 ; X<_dimx ; X++){
		for (int Y = 0 ; Y<_dimy ; Y++){
			fieldData << X << " " << Y << " " << matrix[X][Y].V << " " << dx.matrix[X][Y].V << " " << dy.matrix[X][Y].V  << std::endl ;
			
		}
	}
	
	fieldData.close();
}

