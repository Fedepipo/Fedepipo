#ifndef DLLIST
#define DLLIST
#include "DLNode.h"
#include<iostream>
using namespace std;

template<typename T>
class DLList {
    protected:
        DLNode<T>* head;
        DLNode<T>* tail;
        int size = 0;

    public:
        DLList() : head(nullptr), tail(nullptr) {}

        bool isEmpty() {
            return head == nullptr && tail == nullptr && size == 0;
        }

        void insert(T val) {
            if(this->isEmpty()) {
                head = new DLNode<T>(val);
                tail = head;
                size++;
                return;
            }
        }

        void insertHead(T val) {
            if(this->isEmpty()) {
                this->insert(val);
                return;
            }

            DLNode<T> *ptr = new DLNode<T>(val);
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
            size++;
        }

        void insertTail(T val) {
            if(this->isEmpty()) {
                this->insert(val);
                return;
            }

            DLNode<T> *ptr = new DLNode<T>(val);
            tail->next = ptr;
            ptr->prev = tail;
            tail = ptr;
            size++;
        }

        void insertInOrderC(T val) {
            if(this->isEmpty()) {
                this->insert(val);
                return;
            }

            if(head->val >= val) {
                this->insertHead(val);
                return;
            }

            if(tail->val <= val) {
                this->insertTail(val);
                return;
            }

            DLNode<T> *ptr = head;
            while(ptr->next && ptr->val <= val) {
                if(ptr->next->val >= val) {
                    break;
                }
                ptr = ptr->next;
            }

            DLNode<T> *temp = new DLNode<T>(val);
            temp->next = ptr->next;
            temp->prev = ptr;
            ptr->next->prev = temp;
            ptr->next = temp;
            size++;
        }

        void removeHead() {
            if(this->isEmpty()) {
                cout << "Empty list" << endl;
                return;
            }

            if(head == tail) {
                DLNode<T> *ptr = head;
                head = nullptr;
                tail = nullptr;
                size--;
                delete ptr;
                return;
            }

            DLNode<T> *ptr = head;
            head->next->prev = nullptr;
            head = head->next;
            size--;
            delete ptr;
        }

        void removeTail() {
            if(this->isEmpty()) {
                cout << "Empty list" << endl;
                return;
            }

            if(head == tail) {
                DLNode<T> *ptr = head;
                head = nullptr;
                tail = nullptr;
                delete ptr;
            }

            DLNode<T> *ptr = tail;
            ptr->prev->next = nullptr;
            tail = ptr->prev;
            size--;
            delete ptr;
        }

        void remove(T val) {
            if(this->isEmpty()) {
                cout << "Empty list" << endl;
                return;
            }

            if(head->val == val) {
                this->removeHead();
                return;
            }
            else if(tail->val == val) {
                this->removeTail();
                return;
            }

            DLNode<T> *ptr = head;
            while(ptr->next && ptr->val != val) {
                ptr = ptr->next;
            }

            if(!(ptr->next)) {
                cout << "Element not found" << endl;
                return;
            }

            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            size--;
            delete ptr;
        }

        
        friend ostream& operator<<(ostream& os, DLList<T> &list) {
            os << "List size = " << list.size << ", head = " << list.head << ", tail = " << list.tail << endl;
            DLNode<T> *ptr = list.head;
            while(ptr) {
                os << '\t' << *ptr << endl;
                ptr = ptr->getNext();
            }
            return os;
        }
};



#endif