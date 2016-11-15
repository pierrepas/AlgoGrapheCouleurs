#pragma once

#include "sommet.hpp"
#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include "graphe.hpp"
#include <sstream>
#include <fstream>

class ConjonctionClauses{
    private:

    int nbVariables, nbClauses;
    struct Clause{
        int a,b,c;
        Clause(int a, int b, int c): a(a), b(b), c(c) {}
    };

    public:
    Graphe toGraph();
    std::vector<Clause> clauses;
    ConjonctionClauses();
    ConjonctionClauses(int nbVariables, int nbClauses);
    ConjonctionClauses parse(std::ifstream & in);
    ConjonctionClauses parseVariables(std::string s);
    ConjonctionClauses parseClauses(std::ifstream & in);
};
