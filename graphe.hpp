#pragma once

#include "sommet.hpp"
#include <iostream>
#include <vector>
#include <assert.h>
#include <string>

class Graphe{
    private :
        std::vector<Sommet> sommets;
        int nbSommets;

    public :
        Graphe();
        Graphe parseLigne(std::string ligne, Graphe g, std::vector<std::string> noms);
        std::vector<std::string> parseNoms(std::string s, Graphe g);
        Graphe parseSommets(std::ifstream & in);
        void ajoutSommet();
        void ajoutSommet(std::string nom);
        void ajoutArete(int s1, int s2);
        void afficheSommets();
        bool algoNaif();
        bool algoOpti();
};

