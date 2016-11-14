#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "sommet.hpp"
#include "graphe.hpp"
#include "conjonctionClauses.hpp"

using namespace std;

int main(int argc, char * argv[]){
    if(argc != 2){
        cerr << "Veuillez entrer le nom du fichier comme paramètre." << endl;
        return 1;
    }
    ifstream fichier( argv[1] );
    Graphe g;
    g.parseSommets(fichier);
    g.afficheSommets();
    return 0;
}
