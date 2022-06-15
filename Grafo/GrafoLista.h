#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H
#include<iostream>
#include "List.h"
using namespace std;

//ESTENDO LA CLASSE List IN MODO DA AVERE IL VERTICE NELLA head E LA LISTA DI ADIACENZA NEI SUCCESSORI
template<typename T>
class GraphVertex : public List<T> {
    public:
        GraphVertex(T key) : List<T>() {
            List<T>::insert(key);
        }

        friend ostream& operator<<(ostream& os, GraphVertex<T> v) {
            os << "Graph Vertex with key = " << v.head->getVal() << ": ";
            os << "\tAdjecency List: ";
            Node<T> *ptr = v.getHead();
            while(ptr) {
                os << " -> " << ptr->getVal();
                ptr = ptr->getNext();
            }
            return os;
        }
};

template<typename T>
class GraphList {
    List< GraphVertex<T> > vertices;
    int nVertices = 0;
    bool isOriented;

    public:
        GraphList(bool isOriented = true) : isOriented(isOriented) {}

        void addVertex(T key) {
            GraphVertex<T> toAdd(key);
            vertices.insertTail(toAdd);
            nVertices++;
        }

        void addEdge(T key1, T key2) {

            Node< GraphVertex<T> >* node1 = this->search(key1);
            Node< GraphVertex<T> >* node2 = this->search(key2);

            if(node1 && node2) {
                node1->getVal().insertTail(key2);
                if(!this->isOriented) {
                    node2->getVal().insertTail(key1);
                }
            }
        }

        Node< GraphVertex<T> >* search(T key) {
            if(nVertices == 0) {
                return NULL;
            }

            Node<GraphVertex<T>> *ptr = vertices.getHead();
            while(ptr) {
                if(key == ptr->getVal().getHead()->getVal()) {
                    return ptr;
                }
                ptr = ptr->getNext();
            }
            return NULL;
         }

        friend ostream& operator<<(ostream& os, GraphList<T> &g) {
            os << g.vertices << endl;
            return os;
         }
};


#endif