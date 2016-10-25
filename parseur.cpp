#include "graphe.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


// Fonction appelée sur chaque ligne, génère les arêtes entre graphes
Graphe parseLigne(string ligne, Graphe g, vector<string> noms){
    string sommetCourant;
    int iSommetCourant = -1;
    stringstream fluxLigne(ligne);
    fluxLigne >> sommetCourant;
    for (int i=0; i= noms.size(); i++){
        if(sommetCourant.compare(noms[i]) == 0)
            iSommetCourant = i;
    }
    //On s'assure que le sommet a bien été matché
    assert(iSommetCourant != -1);
    while(fluxLigne){
        string sommetMatch;
        int iSommetMatch = -1;
        fluxLigne >> sommetMatch;
        for(int i=0; i= noms.size(); i++){
            if(sommetMatch.compare(noms[i]) == 0)
                iSommetMatch = i;
        }
        //On s'assure que le sommet a bien été matché
        assert(iSommetMatch != -1);
        g.ajoutArete(iSommetCourant, iSommetMatch);
    }
    return g;
}

// Fonction appelée sur la première ligne, affecte l'ordre des graphes
// en fonction de leur nom.
vector<string> parseNoms(string s, Graphe g){
    vector<string> noms;
    string nom;
    int pos;
    while(pos < s.size()){
        string delimiter =" ";
        nom = s.substr(0, s.find(delimiter));
        noms.push_back(nom);
        pos += nom.size();
        g.ajoutSommet();
    }
    return noms;
}

//Génère les sommets du graphe en fonction du ficher d'entrée.
Graphe parseSommets(ifstream in){
    vector<string> noms;
    Graphe g = Graphe();
    string premiereLigne; // Contient les sommets
    getline(in, premiereLigne);
    noms = parseNoms(premiereLigne, g);
    string ligne;
    while(in){
        getline(in,ligne);
        g = parseLigne(ligne, g, noms);
    }
}
