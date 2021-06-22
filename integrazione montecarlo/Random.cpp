#include "Random.h"
#include "Gauss.h"
#include <cmath>

using namespace std;

Random::Random() {
	m_a=1664525;
	m_c=1013904223;
	m_m=pow(2,31);
	m_seed=0;
}

Random::Random(unsigned int seed) {
	m_a=1664525;
	m_c=1013904223;
	m_m=pow(2,31);
	m_seed=seed;
}

Random::~Random() { }

void Random::SetA(unsigned int a) {m_a=a;}
void Random::SetC(unsigned int c) {m_c=c;}
void Random::SetM(unsigned int m) {m_m=m;}

double Random::Rand() {
	unsigned int n;
	n=(m_a*m_seed+m_c)%m_m;
	double d;
	d=(n*1.)/(m_m-1);
	m_seed=n;
	return d;
}

double Random::BoxMuller(double mu, double sigma) { //mu=mean
	double s=this->Rand();
	double t=this->Rand();
	double g=sqrt(-2.*log(s))*cos(2*M_PI*t);

	return mu+sigma*g;
}

double Random::Exp(double rate) {
	double s=Rand();

	return -rate*log(s);
}

double Random::AcceptReject(double n, double mu, double sigma) { //number of sigma, aspected value, sigma
	Gauss G(mu,sigma);
	double b=mu+sigma*n;
	double a=mu-sigma*n;
	double x;
	double y;
	do {	
	double s=Rand();
	double t=Rand();
	double max=G.Eval(mu);	
	y=max*t;
	x=a+(b-a)*s;}
	while(y>G.Eval(x));

	return x; 
}



