#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "sommet.hpp"
#include "graphe.hpp"
#include "conjonctionClauses.hpp"

using namespace std;

int main(int argc, char * argv[]){
    bool coloriable;
    if(argc != 2){
        cerr << "Veuillez entrer le nom du fichier comme paramètre." << endl;
        return 1;
    }
    ifstream fichier( argv[1] );
    Graphe g;
    g.parseSommets(fichier);
    coloriable = g.algoNaif();
    if(coloriable)
        cout << "Le graphe est coloriable, voici une solution possible:" << endl;
    g.afficheSommets();
    return 0;
}
