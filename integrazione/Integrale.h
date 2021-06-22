#ifndef _Integrale_h_
#define _Integrale_h_

#include"FunzioneBase.h"

class Integrale {

	public:

	Integrale(double a, double b, const FunzioneBase *funzione);
	double MidPoint(unsigned int nstep);
	double Simpson(unsigned int nstep);
	double TrapeziSenzaPrecisione(unsigned int nstep);
	double Trapezi(double precision);

	private:

	const FunzioneBase *m_integranda;
	double m_a;
	double m_b;
};

#endif
