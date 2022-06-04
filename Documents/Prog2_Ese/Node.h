#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

template<typename T>
class Node {
    T val;
    Node<T> *next;

    template<typename U>
    friend class List;

    public:
        Node(T valore) : val(valore) {
            next = nullptr;
        }

        Node<T>* getNext() {
            return this->next;
        }
        
        friend ostream& operator<<(ostream& os, Node<T> &node) {
            os << "&node = " << &node << ", node val = " << node.val << ", next = " << node.next << endl;
            return os;
        }
};


#endif