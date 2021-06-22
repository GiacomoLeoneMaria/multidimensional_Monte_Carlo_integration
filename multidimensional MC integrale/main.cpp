#include "Integrale.h"
#include "Vettore.h"
#include <iostream>

using namespace std;

int main() {

Vettore inf(2);
Vettore sup(2);
unsigned int N=1000;

inf.SetComponent(0,1.);
inf.SetComponent(1,1.);
sup.SetComponent(0,2.);
sup.SetComponent(1,2.);

MediaMC myMediaMC;
FunzioneScalareBase *f=new Funzione();

cout << myMediaMC.Passo(f,inf,sup,N) << endl;

return 0;
}	

