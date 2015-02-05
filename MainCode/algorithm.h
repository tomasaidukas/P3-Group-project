#ifndef TEST1_H
#define TEST1_H


#include <iostream>
#include <fstream>
#include "mesh.h"
#include "CImg.h"
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
  double md_error;
  double md_tolerance;//error tolerance
  
  Algorithm(double, double, double);     //constructor
  ~Algorithm();    //destructor
  void runAlgorithm();
  void setBoundary(double);
  
  };
  
  #endif
