#include <iostream>
#include "TArrow.h"
using namespace std;

void eField()
{
    
    TCanvas *c1 = new TCanvas("c1","c1",800,800);
    c1 -> cd(1);
    TGraph2D *g1 = new TGraph2D("ElectricField/Enumerical.txt");
    g1->Draw("ARR");
    c1->SaveAs("./Plots/Enumerical.png");
    
    TCanvas *c2 = new TCanvas("c2","c2",800,800);
    c2 -> cd(1);
    TGraph2D *g2 = new TGraph2D("ElectricField/EnumCircle.txt");
    g2->Draw("ARR");
    c2->SaveAs("./Plots/EnumCircle.png");
    
}