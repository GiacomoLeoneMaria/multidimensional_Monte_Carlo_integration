#ifndef _Random_h_
#define _Random_h_

class Random {

	public:
	Random();
	Random(unsigned int seed);
	~Random();
	
	void SetA(unsigned int a);
	void SetC(unsigned int c); 
	void SetM(unsigned int m);
	
	double Rand();
		
	private:

	unsigned int m_a;
	unsigned int m_c;
	unsigned int m_m;
	unsigned int m_seed;
};

#endif
