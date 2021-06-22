#include"VettoreLineare.h"
#include"Vettore.h"
#include<iostream>

using namespace std;

VettoreLineare::VettoreLineare(unsigned int a):Vettore(a) { }

VettoreLineare::~VettoreLineare() { }

//somma tra due vettori
VettoreLineare VettoreLineare::operator+(const VettoreLineare &V) const {
	VettoreLineare v(GetN());
	if (GetN()!=V.GetN()) {
		cerr << " vettori di dimensione diversa " << endl;
	return -1;}
	
	for (int i=0; i<GetN(); i++) {
		v.SetComponent(i,V.GetComponent(i)+GetComponent(i));}
	
	return v;
}

//prodotto tra scalare e vettore
VettoreLineare VettoreLineare::operator*(const double x) const {
	VettoreLineare v(GetN());
	for (int i=0; i<GetN(); i++) {
		v.SetComponent(i,x*GetComponent(i));}
	
	return v;
}
		
//prodotto scalare tra due vettori	
double VettoreLineare::operator*(const VettoreLineare &V) const {
	if (GetN()!=V.GetN()) { 
		cerr << " vettori di dimensione diversa " << endl;
	return -1;}
	double k=0;
	for (int i=0; i<GetN(); i++) {
		k+=GetComponent(i)*V.GetComponent(i);	}
	
	return k;
}		
		





	
