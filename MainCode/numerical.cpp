#include "numerical.h"


/*************************************************
 * Constructor
 * Takes in the tolerance, maximum potential and 
 * file name as arguments
 *************************************************/
Numerical::Numerical(double tol, double maxV1, double maxV2, double maxV3, std::string str)
{
  //load the image
  image.load(str.c_str());
  
  //input arguments
  _tol = tol;
  
  //potential values for red, green and blue colors
  _maxV1 = maxV1;
  _maxV2 = maxV2;
  _maxV3 = maxV3;
  
  //image dimensions
  _dimx = image.width();  
  _dimy = image.height();
  
  //allocate new arrays
  _PMesh = Mesh(_dimx, _dimy);
  _SMesh = Mesh(_dimx, _dimy);

  //set all values to zero initialy
  _PMesh.setAllZero();
  _SMesh.setAllZero();
  
  //set the boundaries  
  setBoundary();
  
  //calculate the over-relaxation parameter
  //which depends on the array size
  _orp = TopAlg::ORP();
  
  //counter to see total number of iterations
  _iter = 0;
}


/*************************************************
 * Sets the boundary as shown in the image file
 * Green is the _maxV2 potential
 * Red is _maxV1 potetial
 * Blue is _maxV3 potential
 *************************************************/
void Numerical::setBoundary()
{
    // set the boundaries from an image file
    for (int y=0 ; y<_dimy ; y++){
	for (int x=0 ; x<_dimx ; x++){
	    if( ((int) image(x,y,0,0) == 255) && ((int)image(x,y,0,1)==0) && ((int)image(x,y,0,2) == 0) ){
		_PMesh.setV(_maxV1,x,y);
		_PMesh.setisBoundary(true, x,y);
		_SMesh.setV(_maxV1,x,y);
		_SMesh.setisBoundary(true, x,y);
	    }else if( ((int) image(x,y,0,0) == 0) && ((int)image(x,y,0,1)==255) && ((int)image(x,y,0,2) == 0) ){
		_PMesh.setV(_maxV2,x,y); 
		_PMesh.setisBoundary(true, x,y);
		_SMesh.setV(0,x,y);
		_SMesh.setisBoundary(true, x,y);
	    }else if( ((int) image(x,y,0,0) == 0) && ((int)image(x,y,0,1)==0) && ((int)image(x,y,0,2) == 255) ){
		_PMesh.setV(_maxV3,x,y);
		_PMesh.setisBoundary(true, x,y);
		_SMesh.setV(_maxV3,x,y);
		_SMesh.setisBoundary(true, x,y);
	    }
	}
    }
}


Numerical::~Numerical(){}
