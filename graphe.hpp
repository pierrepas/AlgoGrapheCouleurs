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
        void ajoutSommet();
        void ajoutArete(int s1, int s2);
        void afficheSommets();
        bool algoNaif();
        bool algoOpti();
};

