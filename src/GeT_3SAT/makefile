CXX=g++ -std=c++11 -c

all: solution

solution: main.o sommet.o graphe.o conjonctionClauses.o
	g++ -std=c++11 main.o sommet.o graphe.o conjonctionClauses.o -o solution

sommet.o: sommet.cpp
	${CXX} sommet.cpp

graphe.o: graphe.cpp sommet.hpp
	${CXX} graphe.cpp

conjonctionClauses.o: conjonctionClauses.cpp graphe.hpp
	${CXX} conjonctionClauses.cpp

main.o: main.cpp conjonctionClauses.hpp graphe.hpp sommet.hpp
	${CXX} main.cpp

clean:
	rm -f *.o solution
