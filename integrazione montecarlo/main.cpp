#include "Integrale.h"
#include "Seno.h"
#include "FunzioneBase.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

  double a=0.;
	double b=M_PI;
 	TApplication app("app",0,0);
	TGraph *HoM=new TGraph();
	TGraph *M=new TGraph();
  HoM->SetTitle("Hit or Miss dev.stand. 1000 iteration"); 
  M->SetTitle("Media dev.stand. 1000 iteration");
	
	FunzioneBase *seno=new Seno();
	Integrale *integrale=new Integrale(a,b,seno);

  cout << setw(10) << "k" << "\t" << setw(20) << "pow(10,k)" << setw(15) << "media" << setw(20) << "  hitorMiss" << endl;
  for(int k=1; k<6; k++) {
  double v[1000];
  double w[1000];
  double sommav=0;
  double sommaw=0;
	for(int i=1; i<=1000; i++) {
  double a=integrale->MediaMC(pow(10,k),i);
  double b=integrale->HitorMissMC(pow(10,k),i);
  v[i]=a;
  w[i]=b;
  sommav+=a;
  sommaw+=b;}
  double mediav=sommav/1000;
  double mediaw=sommaw/1000;
  cout << setw(10) << k << " media : " << setw(20) << pow(10,k) << "\t" << setw(15) << mediav << "\t" << setw(15) << mediaw << endl;
  double sigv=0;
  double sigw=0;
  for(int i=0; i<1000; i++) {
  sigv+=pow(v[i]-mediav,2);
  sigw+=pow(w[i]-mediaw,2);}
  double sigmav=sqrt(sigv/1000);
  double sigmaw=sqrt(sigw/1000);
  cout << setw(10) << k << " dev.stand. : " << setw(15) << pow(10,k) << "\t" << setw(15) << sigmav << "\t" << setw(15) << sigmaw << endl;
  
	HoM->SetPoint(k,pow(10,k),sigmaw);
	M->SetPoint(k,pow(10,k),sigmav);
	}
  
  cout << "if we want a precision of 0.001, than we should use " << pow(10,5) << " points " << endl; 
  
	TCanvas *myCanvas1=new TCanvas("c1","c1");
  TCanvas *myCanvas2=new TCanvas("c2","c2");
	myCanvas1->cd();
  HoM->GetXaxis()->SetTitle("punti");
  HoM->GetYaxis()->SetTitle("sigma");
	HoM->Draw("AL*");
	myCanvas2->cd();
  M->GetXaxis()->SetTitle("punti");
  M->GetYaxis()->SetTitle("sigma");
	M->Draw("AL*");
 
  app.Run();

  return 0;
}
