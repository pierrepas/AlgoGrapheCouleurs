#include "graphe.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "sommet.hpp"
#include "parseur.cpp"

using namespace std;

int main(void){
    ifstream ifs("3C_vrai", ifstream::in);
    cout << "Ajout des sommets" << endl;
    Graphe g = parseSommets(ifs);
    cout << "Sommets Ajoutés" << endl;
    g.afficheSommets();
    return 0;
}
