//default header files
#include<iostream>

//user-defined header files
#include "algorithm.h"
#include "mesh.h"
#include "CImg.h"


int main(){

  Algorithm algorithm(1.5,500,1);//sets up the algorithm variables
  algorithm.runAlgorithm();

    //CImg<unsigned char> image("potential.png"), empty(40,40,1,3);	
    /*
	int width = image.width();
    int height = image.height();
    
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            cout << "(" << x << "," << y << ") ="
                 << " R" << (int)image(x,y,0,0)
                 << " G" << (int)image(x,y,0,1)
                 << " B" << (int)image(x,y,0,2) << endl;*/
    return 0;
}
