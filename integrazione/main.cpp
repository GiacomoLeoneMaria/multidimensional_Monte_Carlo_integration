#include"Integrale.h"
#include"Seno.h"
#include"FunzioneBase.h"
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cmath>

using namespace std;

int main(int argc, char** argv) {

	if(argc!=2) {
	cerr << " inserire: " << argv[0] << ", <nstep>" << endl;
	return -1;
	}

	double a=0;
	double b=M_PI;
	int nstep=atoi(argv[1]);
	double precision;
	cout << "precisione con cui calcolare l'integrale con metodo dei trapezi: ";
	cin >> precision; 

	FunzioneBase *seno=new Seno();
	Integrale *integrale=new Integrale(a,b,seno);

	for(int i=1; i<nstep; i++) {
	cout << setprecision(10) << integrale->MidPoint(i) << "\t" << " errore: " << integrale->MidPoint(i)-2 << endl;
	cout << setprecision(10) << integrale->Simpson(nstep) << endl;
	cout << setprecision(10) << integrale->TrapeziSenzaPrecisione(nstep) << endl;
	cout << setprecision(10) << integrale->Trapezi(precision) << endl;	
	}
	
return 0;
}
