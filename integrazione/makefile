complila: main.o Seno.o Integrale.o
	c++ main.o Seno.o Integrale.o -o integrale

main.o: main.cpp FunzioneBase.h Integrale.h Seno.h
	c++ -c main.cpp -o main.o

Integrale.o: Integrale.cpp Integrale.h FunzioneBase.h
	c++ -c Integrale.cpp -o Integrale.o

Seno.o: Seno.cpp Seno.h FunzioneBase.h
	c++ -c Seno.cpp -o Seno.o


