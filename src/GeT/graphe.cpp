#include "graphe.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define NB_COULEURS 3

using namespace std;


void Graphe::ajoutSommet(){
    Sommet s(nbSommets ++);
    sommets.push_back(s);
}

void Graphe::ajoutSommet(string nom){
    Sommet s(nbSommets ++);
    s.nom = nom;
    sommets.push_back(s);
}

void Graphe::ajoutArete(int s1, int s2){
    if((s1 >= sommets.size() || s2 > sommets.size())){
        cerr << "Il y a " << sommets.size() << " sommets." << endl;
        cerr << "On essaie d'insérer à la case " << max(s1, s2) << endl;
        assert(s1 < sommets.size() && s2 < sommets.size());
    }
    cout  << "Création d'une arête entre " << sommets[s1].nom << " et " << sommets[s2].nom << endl;
    sommets[s1].ajoutSommet(sommets[s2]);
    sommets[s2].ajoutSommet(sommets[s1]);
}

void Graphe::afficheSommets(){
    cout << "Affichage des sommets" << endl;
    for(int i=0; i<sommets.size(); i++){
        sommets[i].afficheVoisins();
    }
}

bool Graphe::genereEtTeste(){
    cout << "Lancement de l'algo naïf" << endl;
    for(int i=0; i<sommets.size(); i++){
        if (!sommets[i].assigneCouleur()){
            cout << "Le graphe n'est pas coloriable." << endl;
            return false;
        }
    }
    cout << "Le graphe est coloriable!" << endl;
    return true;
}

bool Graphe::algoOpti(){
    return false;
}

//Fonction appelée sur chaque ligne, génère les arêtes entre graphes
void Graphe::parseLigne(string ligne, vector<string> noms){
    cout << "Parsing de la ligne " << ligne << endl;
    string sommetCourant, sommetMatch;
    //for (int i=0; i<noms.size(); i++) cout << noms[i] << endl;
    int iSommetCourant = -1;
    int iSommetMatch = -1;
    stringstream fluxLigne(ligne);
    fluxLigne >> sommetCourant;
    for (int i=0; (i< noms.size()); i++){
        if(sommetCourant.compare(noms[i]) == 0)
            iSommetCourant = i;
    }
    fluxLigne >> sommetMatch;
    for (int i=0; (i< noms.size()); i++){
        if(sommetMatch.compare(noms[i]) == 0)
            iSommetMatch = i;
    }

    //On s'assure que le sommet a bien été matché
    assert(iSommetCourant != -1);
    assert(iSommetMatch != -1);
    ajoutArete(iSommetCourant, iSommetMatch);
}

// Fonction appelée sur la première ligne, affecte l'ordre des graphes
// en fonction de leur nom.
vector<string> Graphe::parseNoms(string s){
    cout << "Analyse des noms" << endl;
    cout << "Liste des sommets du fichier: " << s << endl;
    stringstream ss(s);
    vector<string> noms;
    while (ss){
        string sommetEnCours;
        ss >> sommetEnCours;
        noms.push_back(sommetEnCours);
        Sommet sommet(sommetEnCours);
        sommets.push_back(sommet);
    }
    sommets.pop_back();
    return noms;
}

//Génère les sommets du graphe en fonction du ficher d'entrée.
void Graphe::parseSommets(ifstream & in){
    cout << "Lancement du parsing " << endl;
    vector<string> noms;
    string premiereLigne; // Contient les sommets
    getline(in, premiereLigne); // pour ignonrer la 1ère ligne du fichier graphes
    getline(in, premiereLigne);
    noms = parseNoms(premiereLigne);
    cout << "Analyse Terminée, " << sommets.size() << " sommets trouvés." << endl;
    string ligne;
    getline(in,ligne);
    while(ligne.compare("}") != 0){
        parseLigne(ligne, noms);
        getline(in,ligne);
    }
    cout << "Parsing terminé." << endl;
}

int Graphe::chercheSommet(std::string s){
    for(int i=0; i<sommets.size(); i++){
        if(s.compare(sommets[i].nom) == 0){
            return i;
        }
    }
};

