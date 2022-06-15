#ifndef NODE_H
#define NODE_H


#include<iostream>
using namespace std;

template<typename T>
class Node {
    T valore;
    Node<T>* next;

    template<typename U>
    friend class List; //dichiaro la classe List come friend per accedere ai metodi privati di Node
    
    public:
        Node(T val) : valore(val) {
            next = nullptr;
        }

        Node<T>* getNext() const { return this->next; }

        T getVal() const { return this->valore; }

        friend ostream& operator<<(ostream& os, const Node<T> &node) {
        os << "node& " << &node << "  node val = " << node.valore << " - next = " << node.next << endl;
        return os;
    }
};

#endif