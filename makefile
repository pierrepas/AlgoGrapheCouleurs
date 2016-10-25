CXX=g++ -std=c++11 -c

all: solution

solution: main.o sommet.o graphe.o parseur.o
	g++ -std=c++11 main.o sommet.o graphe.o parseur.o -o solution

main.o: main.cpp graphe.hpp sommet.hpp
	${CXX} main.cpp

sommet.o: sommet.cpp graphe.hpp
	${CXX} sommet.cpp

graphe.o: graphe.cpp sommet.hpp
	${CXX} graphe.cpp

parseur.o: parseur.cpp graphe.cpp
	${CXX} parseur.cpp

clean:
	rm *.o solution
