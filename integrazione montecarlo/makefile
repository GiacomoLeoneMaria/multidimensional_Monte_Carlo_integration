LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

complila: main.o Seno.o Integrale.o Gauss.o Random.o
	c++ main.o Seno.o Integrale.o Gauss.o Random.o -o mcintegral ${INCS} ${LIBS} 

main.o: main.cpp FunzioneBase.h Integrale.h Seno.h
	c++ -c main.cpp -o main.o ${INCS}

Integrale.o: Integrale.cpp Integrale.h FunzioneBase.h Random.h 
	c++ -c Integrale.cpp -o Integrale.o

Seno.o: Seno.cpp Seno.h FunzioneBase.h
	c++ -c Seno.cpp -o Seno.o

Random.o: Random.cpp Random.h Gauss.h
	g++ -c Random.cpp -o Random.o

Gauss: Gauss.cpp Gauss.h
	g++ -c Gauss.cpp -o Gauss.o
	
