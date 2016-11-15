#include "sommet.hpp"

#define NB_COULEURS 3

using namespace std;


void Sommet::setCouleur(char c){
    couleur = c;
}

Sommet::Sommet(string s){
    couleur = -1;
    nom = s;
}

bool Sommet::isAssigned(){
    if( couleur == -1 )
        return false;
    return true;
}

void Sommet::afficheVoisins(){
    cout << "Couleur de " << nom << " : " << (int)couleur << ". ";
    cout << "Voisins de " << nom << " : ";
    for(int i=0; i<sommetsAdjacents.size(); i++){
        cout << sommetsAdjacents[i]->nom << ", ";
    }
    if(couleur != -1) {
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

void Sommet::ajoutSommet(Sommet & s){
    sommetsAdjacents.push_back(&s);
}

Sommet::Sommet(int i){
    indice = i;
    couleur = -1;
}

bool Sommet::verifNonCouleurAdjacentes(){
    for(int i=0; i < sommetsAdjacents.size(); i++){
        if(couleur == sommetsAdjacents[i]->getCouleur()){
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
        if(sommetsAdjacents[i]->isAssigned())
            tabCouleurs[sommetsAdjacents[i]->couleur] = true;
        // Si on ne peut pas assigner de couleur valide aux sommets adjacents,
        // le graphe n'est pas valide.
    }

    for (int i=0; i<NB_COULEURS; i++){
        if(!tabCouleurs[i]){ // la couleur n'a pas été assignée
            cout << "indice du tableau: " << i << endl;
            couleur = i;
            return true;
        }
    }
    return false;
}
