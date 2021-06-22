complila: main.o Integrale.o Random.o Vettore.o VettoreLineare.o
	c++ Vettore.o VettoreLineare.o main.o Integrale.o Random.o -o multidimensional 

main.o: main.cpp Integrale.h 
	c++ -c main.cpp -o main.o 

Integrale.o: Integrale.cpp Integrale.h Random.h 
	c++ -c Integrale.cpp -o Integrale.o

Random.o: Random.cpp Random.h 
	g++ -c Random.cpp -o Random.o

Vettore.o: Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

VettoreLineare.o: VettoreLineare.cpp VettoreLineare.h Vettore.h
	g++ -c VettoreLineare.cpp -o VettoreLineare.o
