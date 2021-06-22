#include"Integrale.h"
#include"FunzioneBase.h"
#include<algorithm>
#include<cmath>
#include<iostream>

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

double Integrale::MidPoint(unsigned int nstep) {

	double h=(m_b-m_a)/nstep;
	double sum=0;

	for(int i=0; i<nstep; i++) {
	double x=m_a+(i+0.5)*h;
	sum+=m_integranda->Eval(x);
	}
	double integrale=sum*h;
	
	return integrale;
}

//other possible implementation of Simpson Integral

/*double Integrale::Simpson(unsigned int nstep) {

	if (nstep%2==1) {
	nstep=nstep+1;
	}

	double somma1,somma2,somma3;
	double h=(m_b-m_a)/nstep;
	
	double x=m_a;
	somma1=(1./3.)*m_integranda->Eval(x);

	for(int i=0; i<nstep; i++) {
	x=m_a+i*h;
	somma2+=((2.+(i%2)*2.)/3.)*m_integranda->Eval(x);
	}

	x=m_b;
	somma3+=(1./3.)*m_integranda->Eval(x);

	double integrale=(somma1+somma2+somma3)*h;

	return integrale;
}*/

double Integrale::Simpson(unsigned int nstep) {

	if (nstep%2==1) {
	nstep=nstep+1;
	}
	
	double h=(m_b-m_a)/nstep;
	double sum1;
	double sum2;
	
	for(int i=0; i<nstep; i++) {
	double x=m_a+i*h;
	if(i%2==0) {
	sum1+=2./3.*m_integranda->Eval(x);}
	else {
	sum2+=4./3.*m_integranda->Eval(x);}
	}
	
	return h*(sum1+sum2+1./3.*(m_integranda->Eval(m_a)+m_integranda->Eval(m_b)));
}


double Integrale::TrapeziSenzaPrecisione(unsigned int nstep) {
	
	double sum;
	double h=(m_b-m_a)/nstep;
	for(int i=1; i<nstep-1; i++) {
	double x=m_a+h*i;
	sum+=m_integranda->Eval(x);}

	return 1./2.*h*(2*sum+m_integranda->Eval(m_a)+m_integranda->Eval(m_b));
}	

//integration with formula of trapezoids with fixed precision
double Integrale::Trapezi(double precision) {
	
	double sum0=(m_integranda->Eval(m_a)+m_integranda->Eval(m_b))/2.;
	double integrale0=sum0*(m_b-m_a);
	int i=1;
	double h;
	double delta;
	
	h = (m_b-m_a)/2.;
	delta=h;
	
	double sumi=sum0+m_integranda->Eval(m_a+h);
	double integralei=sumi*h;
	
	while (abs(integralei-integrale0)>precision) {
	
		integrale0=integralei;
		i++;
		h = (m_b-m_a)/(pow(2,i));
		
		for (int j=0; j<pow(2,i-1); j++)
			sumi+=m_integranda->Eval(m_a+h+j*delta);
		
		integralei=sumi*h;
		delta=h;
	}
	double integrale=integralei;
	
	return integrale;
}






















