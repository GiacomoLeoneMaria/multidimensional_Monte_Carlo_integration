#ifndef _Integrale_h_
#define _Integrale_h_
#include "Vettore.h"

class FunzioneScalareBase {

	public:
	virtual double Eval(const Vettore &x) const=0;
};

class IntegraleBase {
	
	public:
	virtual double Passo(const FunzioneScalareBase *f, const Vettore &inf, const Vettore &sup, unsigned int N) const=0;
};

class Funzione: public FunzioneScalareBase {
	
	public:
	Funzione();
	~Funzione();
	virtual double Eval(const Vettore &x) const;
};
		

class MediaMC: public IntegraleBase {

	public:
	MediaMC();
	~MediaMC();
	virtual double Passo(const FunzioneScalareBase *f, const Vettore &inf, const Vettore &sup, unsigned int N) const;
};

#endif
