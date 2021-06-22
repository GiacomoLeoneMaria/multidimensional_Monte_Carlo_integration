#ifndef _Integrale_h_
#define _Integrale_h_

#include"FunzioneBase.h"

class Integrale {

	public:

	Integrale(double a, double b, const FunzioneBase *funzione);
	double MediaMC(int N, int seed);
	double HitorMissMC(int N, int seed);
	
  private:

	const FunzioneBase *m_integranda;
	double m_a;
	double m_b;
  };

#endif
