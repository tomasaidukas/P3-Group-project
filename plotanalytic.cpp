#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

double phi(int,int,int,double,double);
void analytic(int,int,double,double);

//Function for analytic solution
//Takes as arguments (x,y)-coodinates, lenght L, radius R, electric field E0
double phi(int x, int y, int L, double R, double E0)
{//Define r
  double r=sqrt(x*x+y*y);
 //Define cos(theta)
  double costheta=x/r;
 //Outside circle
  if(x*x+y*y>R*R) return E0*(r-R)*(1+R*L/((L-R)*r))*costheta;
 //Inside circle
  return 0;
}
// Algorithm for plotting the analytic solution
// Takes 3 aguments: distance L, voltage V, radius R 

void analytic(int Lx, int Ly,  double V, double R)
{
	// File for the data
	ofstream data;
        // Electric field
        double E0=V/Lx;
        // Output data
        data.open("data.txt");
        data<<endl;
        for (int X = 0 ; X<=2*Lx ; X++)
	  {for (int Y = 0 ; Y<=2*Ly ; Y++)
	     if(X == 0) data<<-V<<" ";
	      else if(X == 2*Lx) data<<V<<" ";
	       else data<<phi(X-Lx,Y-Ly,Lx,R,E0)<<" ";
	   data<<endl;
	  }         
}

int main()
{
  analytic(25,100,10,5);
	return 0;
}
