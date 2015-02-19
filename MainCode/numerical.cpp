#include "numerical.h"


/*************************************************
 * Constructor
 * Takes in the tolerance, maximum potential and 
 * file name as arguments
 *************************************************/
Numerical::Numerical(double tol, double maxV1, double maxV2, double maxV3, std::string str, int scale)
{
  //load the image
  image.load(str.c_str());
  
  //input arguments
  _tol = tol;
  _scale = scale;

  //potential values for red, green and blue colors
  _maxV1 = maxV1;
  _maxV2 = maxV2;
  _maxV3 = maxV3;
  
  //image dimensions
  _imagex = image.width();  
  _imagey = image.height();
  _dimx = _scale * image.width();
  _dimy = _scale * image.height();

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
    for (int y=0 ; y<_imagey ; y++){
	for (int x=0 ; x<_imagex ; x++){
	    if( ((int) image(x,y,0,0) == 255) && ((int)image(x,y,0,1)==0) && ((int)image(x,y,0,2) == 0) ){
	      for (int p=_scale*x; p<_scale*x+_scale; p++){
		for (int q=_scale*y; q<_scale*y+_scale; q++){
		  _PMesh.setV(_maxV1,p,q);
		  _PMesh.setisBoundary(true,p,q);
		  _SMesh.setV(_maxV1,p,y);
		  _SMesh.setisBoundary(true,p,q);
		}
	      }
	    }else if( ((int) image(x,y,0,0) == 0) && ((int)image(x,y,0,1)==255) && ((int)image(x,y,0,2) == 0) ){
	      for (int p=_scale*x; p<_scale*x+_scale; p++){
		for (int q=_scale*y; q<_scale*y+_scale; q++){
		  _PMesh.setV(_maxV2,p,q); 
		  _PMesh.setisBoundary(true,p,q);
		  _SMesh.setV(_maxV2,p,q);
		  _SMesh.setisBoundary(true,p,q);
		}
	      }
	    }else if( ((int) image(x,y,0,0) == 0) && ((int)image(x,y,0,1)==0) && ((int)image(x,y,0,2) == 255) ){
	      for (int p=_scale*x; p<_scale*x+_scale; p++){
		for (int q=_scale*y; q<_scale*y+_scale; q++){	 
		  _PMesh.setV(_maxV3,p,q);
		  _PMesh.setisBoundary(true,p,q);
		  _SMesh.setV(_maxV3,p,q);
		  _SMesh.setisBoundary(true,p,q);
		}
	      }
	    }
	    
	}
    }
}


Numerical::~Numerical(){}
