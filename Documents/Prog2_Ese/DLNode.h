#ifndef DLNODE_H
#define DLNODE_H
#include<iostream>
using namespace std;

template<typename T>
class DLNode {
    DLNode<T> *next;
    DLNode<T> *prev;
    T val;

    template<typename U>
    friend class DLList;

    public:
        DLNode(T valore) : val(valore), next(nullptr), prev(nullptr) {}

        DLNode<T>* getNext() const { return this->next; }

        DLNode<T>* getPrev() const { return this->prev; }

        friend ostream& operator<<(ostream& os, DLNode<T> &node) {
            os << "&node = " << &node << ", node val = " << node.val << ", prev = " << node.prev << ", next = " << node.next << endl;
            return os;
        }
};


#endif