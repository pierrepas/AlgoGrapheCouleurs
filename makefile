CXX=g++ -Wall -std=c++11 -c

all: solution

solution: main.o sommet.o graphe.o
	g++ -std=c++11 main.o sommet.o graphe.o -o solution

sommet.o: sommet.cpp graphe.hpp
	${CXX} sommet.cpp

graphe.o: graphe.cpp sommet.hpp
	${CXX} graphe.cpp

#parseur.o: parseur.cpp graphe.cpp
#	${CXX} parseur.cpp

main.o: main.cpp parseur.cpp graphe.hpp sommet.hpp
	${CXX} main.cpp

clean:
	rm *.o solution
