#ifndef _Seno_h_
#define _Seno_h_
#include"FunzioneBase.h"
#include<cmath>

class Seno: public FunzioneBase {

	public:

	Seno();
	~Seno();

	virtual double Eval(double x) const {return sin(x);}
};

#endif
