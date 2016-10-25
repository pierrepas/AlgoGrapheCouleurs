#include "graphe.hpp"

#define NB_COULEURS 3

using namespace std;


Graphe::Graphe(){}

void Graphe::ajoutSommet(){
    Sommet s(nbSommets ++);
    sommets.push_back(s);
}

void Graphe::ajoutArete(int s1, int s2){
    for (int i=0; i<sommets.size(); i++){
        assert(s1 < sommets.size() && s2 < sommets.size());
        sommets[s1].ajoutSommet(s2);
        sommets[s2].ajoutSommet(s1);
    }
}

void Graphe::afficheSommets(){
    for(int i=0; i<sommets.size(); i++){
        sommets[i].afficheVoisins();
    }
}

bool Graphe::algoNaif(){
    for(int i=0; i<sommets.size(); i++){
        if (!sommets[i].assigneCouleur()){
            return false;
        }
    }
    return false;
}

bool Graphe::algoOpti(){
    return false;
}
