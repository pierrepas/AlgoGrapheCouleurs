#pragma once

#include <iostream>
#include <vector>
#include <assert.h>


class Sommet{
    private:
        std::vector<Sommet> sommetsAdjacents;
        char couleur;
        int indice;

    public:
        std::string nom;
        Sommet(int i);
        char getCouleur();
        int getIndice();
        void ajoutSommet();
        void ajoutSommet(Sommet s);
        void afficheVoisins();
        bool verifNonCouleurAdjacentes();
        bool assigneCouleur();
        bool isAssigned();
        void setCouleur(char c);
};
