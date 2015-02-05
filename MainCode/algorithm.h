#ifndef TEST1_H
#define TEST1_H


#include <iostream>
#include <fstream>
#include <cmath>
#include "mesh.h"
#include "CImg.h"
#include <cstring>
#define PI  3.141592
using namespace cimg_library;

class Algorithm{
 private:
  int a_dimX, a_dimY;//dimensions of mesh
  Mesh V_Mesh; //Primary Mesh
  Mesh V_TempMesh;
  Mesh EF_dxMesh;
  Mesh EF_dyMesh;
  Mesh EF_Mesh;
  CImg<unsigned char> image;
  
  
  public:
  double md_pot; // Temporary storage variable for potential
  double md_field; // Temporary storage variable for el. field
  double md_orp; //over-relaxation parameter
  double md_error; //the error variable between two iterations in "time"
  double md_tolerance;//error tolerance
  double md_voltage; //specify the voltage
  int counter; //counts the number of iterations taken
  
  Algorithm(double,double, std::string);     //constructor
  ~Algorithm();    //destructor
  void runAlgorithm(); //runs the main algorithm
  void setBoundary(double); //sets the boundaries from an image file
  void eField(Mesh&); //fills in the electric field arrays
  double calcError(Mesh&, Mesh&); //calculates md_error
  double ORP(); //calculates over-relaxation parameter
  
  };
  
  #endif
