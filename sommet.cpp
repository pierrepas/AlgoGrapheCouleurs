#include "sommet.hpp"

#define NB_COULEURS 3

using namespace std;


void Sommet::setCouleur(char c){
    couleur = c;
}

bool Sommet::isAssigned(){
    if( couleur == -1 )
        return false;
    return true;
}

void Sommet::afficheVoisins(){
    cout << "Couleur de "<< indice <<" : " << (int)couleur << ". ";
    cout << "Voisins de "<< indice <<" : ";
    for(int i=0; i<sommetsAdjacents.size(); i++){
        cout << sommetsAdjacents[i].getIndice() << ", ";
    }
    if(verifNonCouleurAdjacentes()){
        cout << "Sommet valide";
    }else{
        cout << "Sommet non valide";
    }
    cout << endl;
}

char Sommet::getCouleur(){
    return couleur;
}

int Sommet::getIndice(){
    return indice;
}

void Sommet::ajoutSommet(Sommet s){
    for(int i=0; i<sommetsAdjacents.size(); i++){
        if (s.indice == sommetsAdjacents[i].getIndice()){
            return;
        }
    }
    sommetsAdjacents.push_back(s);
}

Sommet::Sommet(int i){
    indice = i;
    couleur = -1;
}

bool Sommet::verifNonCouleurAdjacentes(){
    for(int i=0; i < sommetsAdjacents.size(); i++){
        if(couleur == sommetsAdjacents[i].getCouleur()){
            return 0;
        }
    }
    return 1;
}

bool Sommet::assigneCouleur(){
    bool tabCouleurs[NB_COULEURS];

    for (int i=0; i<NB_COULEURS; i++){
        tabCouleurs[i] = false;
    }

    for (int i=0; i<sommetsAdjacents.size(); i++){
        if(sommetsAdjacents[i].isAssigned())
            if(sommetsAdjacents[i].assigneCouleur())
                return false;
        // Si on ne peut pas assigner de couleur valide aux sommets adjacents,
        // le graphe n'est pas valide.
    }
}
