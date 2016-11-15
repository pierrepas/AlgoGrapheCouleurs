#include "conjonctionClauses.hpp"
#include <string>

using namespace std;

string tostring(int i){
    std::ostringstream ost;
    ost << i;
    const std::string s(ost.str());
    return s;
}

Graphe ConjonctionClauses::toGraph(){
    Graphe g;
    g.ajoutSommet("a");
    g.ajoutSommet("b");
    g.ajoutArete(0, 1);
    g.ajoutArete(0, 1);
    g.ajoutSommet("c");
    g.ajoutArete(0, 2);
    g.ajoutArete(1, 2);
    for(int i=1; i<nbVariables+1; i++){
        g.ajoutSommet(tostring(i));
        g.ajoutArete(2, i-1);
        g.ajoutSommet(tostring(-i));
        g.ajoutArete(2, -i+1);
    }
    return g;
}

ConjonctionClauses ConjonctionClauses::parseClauses(ifstream & in){
    ConjonctionClauses cc = ConjonctionClauses(*this);
    for (int i=0; i < nbClauses ; i++){
        int a,b,c;
        in >> a >> b >> c;
        Clause clause(a,b,c);
        cc.clauses.push_back(clause);
    }
}

ConjonctionClauses::ConjonctionClauses(int nbVariables,int nbClauses):
    nbVariables(nbVariables), nbClauses(nbClauses){}

    ConjonctionClauses ConjonctionClauses::parseVariables(string s){
        int nbVariables, nbClauses;
        istringstream istr( s );
        istr >> nbVariables >> nbClauses;
        ConjonctionClauses cc = ConjonctionClauses(nbVariables, nbClauses);
        return cc;
    }

ConjonctionClauses ConjonctionClauses::parse(ifstream & in){
    string premiereLigne;
    getline(in, premiereLigne);
    assert(premiereLigne.compare("3SAT {") == 0);
    getline(in, premiereLigne);
}
