//Contains the function definitions for the Mesh class


#include "mesh.h"


/*************************************************
 * Default constructor
 * If no values are given it initializes a mesh 
 * with dimensions 0
 *************************************************/
Mesh::Mesh():_dimx(0),
	     _dimy(0),
	     matrix(0)
{}


/*************************************************
 * Constructor
 * Creates a mesh with dimensions X and Y
 *************************************************/
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


/*************************************************
 * Copy constructor
 * Allows to initialize a new Mesh equal to some
 * other Mesh
 * syntax: Mesh mesh1(mesh2)
 *************************************************/
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

/*************************************************
 * Assignment operator overload
 * Allows to write Mesh1 = Mesh2
 *************************************************/
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



/*************************************************
 * Destructor
 * It dealocates memory given for the Mesh
 *************************************************/
Mesh::~Mesh()
{
  //deallocate y arrays
  for (int i=0; i<_dimx; i++){
    delete[] matrix[i];
  }
	
	//std::cout << "destroying array " << std::endl;
  //deallocate x array
  delete[] matrix;
}

/*************************************************
 * Set the value of the potentnial for (X,Y) point
 *************************************************/
void Mesh::setV(double d_V, int i, int j)
{
  matrix[i][j].V = d_V;
}

/*************************************************
 * Set (X,Y) point to be a boundary or not
 *************************************************/
void Mesh::setisBoundary(bool b_cond, int i, int j)
{
  matrix[i][j].isBoundary = b_cond;
}

/*************************************************
 * Set all Mesh values to zero
 *************************************************/
void Mesh::setAllZero(){
    for (int X = 0 ; X<_dimx ; X++){
	for (int Y = 0 ; Y<_dimy ; Y++){	
	    matrix[X][Y].V = 0;
	    matrix[X][Y].isBoundary = false;
	}
    }
    
}



/*************************************************
 * Get the potential value of (X,Y) point
 *************************************************/
double Mesh::getV(int i, int j)
{
  return matrix[i][j].V;
}

/*************************************************
 * Get a boolean value true or false for a boundary
 *************************************************/
bool Mesh::getisBoundary(int i, int j)
{
  return matrix[i][j].isBoundary;
}

/*************************************************
 * Get Mesh X dimension
 *************************************************/
int Mesh::getDimX(){
	return _dimx;
}

/*************************************************
 * Get Mesh Y dimension
 *************************************************/
int Mesh::getDimY(){
	return _dimy;
}

/*************************************************
 * Overload the << operator for Meshes
 *************************************************/
std::ostream& operator<<(std::ostream& out, const Mesh& mesh)
{

      for (int j=0; j<mesh._dimy; j++){
	for (int i=0; i<mesh._dimx; i++){
	    out<< mesh.matrix[i][j].V << " ";
	    }
	    out << std::endl;
	}
	
 }
