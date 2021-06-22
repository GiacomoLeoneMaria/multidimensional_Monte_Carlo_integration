#include "Integrale.h"
#include "Random.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

MediaMC::MediaMC() {}
MediaMC::~MediaMC(){}

Funzione::Funzione() {}
Funzione::~Funzione() {}

double Funzione::Eval(const Vettore &x) const {
	return 5./pow(x.GetComponent(0),2)*cos(4.*x.GetComponent(1))*sin(7.*x.GetComponent(0))+10.;
}

double MediaMC::Passo(const FunzioneScalareBase *f, const Vettore &inf, const Vettore &sup, unsigned int N) const {
	
	Random rand(10);
	double somma=0;
	Vettore v(2);
	
	for(int i=0; i<N; i++) {								v.SetComponent(0,inf.GetComponent(0)+rand.Rand()*(sup.GetComponent(0)-inf.GetComponent(0)));
v.SetComponent(1,inf.GetComponent(1)+rand.Rand()*(sup.GetComponent(1)-inf.GetComponent(1)));
	somma+=f->Eval(v);
	}
	
	double integrale=(sup.GetComponent(0)-inf.GetComponent(0))*(sup.GetComponent(1)-inf.GetComponent(1))*somma/N;
	
	return integrale;
}

