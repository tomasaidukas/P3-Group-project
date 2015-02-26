#include <iostream>
using namespace std;

void eField()
{
    
    TCanvas *c1 = new TCanvas("c1","c1",800,800);
    c1 -> cd(1);
    TGraph2D *g1 = new TGraph2D("ElectricField/Enumerical.txt");
    g1->Draw("ARR");
    c1->SaveAs("./Plots/Enumerical.png");
    
}
