#include "Grafo.h"
#include<iostream>
#include "GrafoLista.h"
using namespace std;

int main() {

   /* Grafo<int> g;
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);

    cout << g << endl;*/

    GraphList<int> g(false);

    g.addVertex(10);
    g.addVertex(11);
    g.addVertex(12);
    g.addVertex(13);

    g.addEdge(10, 11);
    g.addEdge(12, 13);
    g.addEdge(13, 11);
    
    cout << g << endl;
}