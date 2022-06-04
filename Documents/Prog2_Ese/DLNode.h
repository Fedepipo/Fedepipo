#ifndef DLNODE
#define DLNODE
#include<iostream>
using namespace std;

template<typename T>
class DLNode {
    T val;
    DLNode<T> *next;
    DLNode<T> *prev;

    template<typename U>
    friend class DLList;

    public:
        DLNode(T valore) : val(valore) {
            next = nullptr;
            prev = nullptr;
        }

        DLNode<T>* getNext() { return this->next; }
        DLNode<T>* getPrev() {return this->prev; }


        friend ostream& operator<<(ostream& os, DLNode<T> &node) {
            os << "&node = " << &node << ", node val = " << node.val << ", next = " << node.next << ", prev = " << node.prev << endl;
            return os;
        }
};



#endif