//Contains class for information about the shapes used
//to define the boundary conditions in the algorithm.
//
//REQUIRED:
//Constructor Code
//Destructor Code (shouldn't be necessary)
//Circle, Triangle and Rectangle subclasses



#ifndef SHAPE_H
#define SHAPE_H

#include<iostream>


//This defines a new type which will represent a point
//in the mesh.
//It will be used to define the position (vertices) of shapes
typedef struct{
  int m_x;
  int m_y
}point;


class Shape{
 private:
  point *vertices;    //array of points
 public:
  Shape();   //Constructor
 ~Shape():   //Destructor
};




#endif
