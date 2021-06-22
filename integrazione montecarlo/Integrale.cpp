#include "Integrale.h"
#include "FunzioneBase.h"
#include "Random.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

Integrale::Integrale(double a, double b, const FunzioneBase *funzione) {

	m_a=a;
	m_b=b;
	m_integranda=funzione;
  
	m_a=min(a,b);
	m_b=max(a,b);
	m_integranda=funzione;
	double sign;
	if(a>b) {
	sign=-1;}
	else {
	sign=1;}
}

//MonteCarlo integration: mean method 
double Integrale::MediaMC(int N, int seed) { 
	Random rand(seed);
	double somma;
	for(int i=0; i<N; i++) {
	double x=m_a+rand.Rand()*(m_b-m_a);
	somma+=m_integranda->Eval(x);}
	double integrale=(m_b-m_a)*somma/N;

	return integrale;
}

//MonteCarlo integration: hit or miss method
double Integrale::HitorMissMC(int N, int seed) {
	Random rand(seed);
	int Ntot=0;
	int Nhit=0;
  double v[N];
	
  for(int i=0; i<N; i++) {
	double x=m_a+rand.Rand()*(m_b-m_a);
	v[i]=m_integranda->Eval(x);}
	double max=v[0];
	for(int i=0; i<N; i++) {
	if(max<v[i]) {
	max=v[i];}	
  }

	for(int i=0; i<N; i++) {
  Ntot++;
	double x=m_a+rand.Rand()*(m_b-m_a);
	double y=rand.Rand()*max;
	if(y<m_integranda->Eval(x)) {
		Nhit++;}
	}
	double integrale=(m_b-m_a)*Nhit/Ntot;
	
	return integrale;
}
	
	


