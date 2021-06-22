#include "Random.h"
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

//Linear congruential generator of random number
double Random::Rand() {
	unsigned int n;
	n=(m_a*m_seed+m_c)%m_m;
	double d;
	d=(n*1.)/(m_m-1);
	m_seed=n;
	return d;
}

