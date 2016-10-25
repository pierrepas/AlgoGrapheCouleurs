#include "graphe.hpp"
#include "sommet.hpp"
using namespace std;

int main(void){
    Graphe g = Graphe();
    g.ajoutSommet();
    g.ajoutSommet();
    g.ajoutSommet();
    g.afficheSommets();
    cout << "Ajout des sommets:" << endl;
    g.ajoutArete(0,1);
    g.ajoutArete(1,2);
    g.ajoutArete(2,0);
    g.afficheSommets();

    return 0;
}
