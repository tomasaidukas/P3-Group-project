#include <iostream>
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
    
    TCanvas *c5 = new TCanvas("c1","c1",800,800);
    c5 -> cd(1);
    TGraph2D *g5 = new TGraph2D("ElectricField/Eanalytical.txt");
    g5->Draw("ARR");
    c5->SaveAs("./Plots/Eanalytical.png");
    
    TCanvas *c6 = new TCanvas("c2","c2",800,800);
    c6 -> cd(1);
    TGraph2D *g6 = new TGraph2D("ElectricField/Eanalytical.txt");
    g6->Draw("CONT10");
    c6->SaveAs("./Plots/EanalyticalPotential.png");
    
    TCanvas *c3 = new TCanvas("c3","c3",800,800);
    c3 -> cd(1);
    TGraph2D *g3 = new TGraph2D("ElectricField/Enumerical.txt");
    g3->Draw("CONT10");
    c3->SaveAs("./Plots/EnumericalPotential.png");
		
    TCanvas *c4 = new TCanvas("c4","c4",800,800);
    c4 -> cd(1);
    TGraph2D *g4 = new TGraph2D("ElectricField/EnumCircle.txt");
    g4->Draw("CONT10");
    c4->SaveAs("./Plots/EnumCirclePotential.png");
		
}
