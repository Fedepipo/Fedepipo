#ifndef DLLIST_H
#define DLLIST_H
#include "DLNode.h"
#include<iostream>
using namespace std;

template<typename T>
class DLList {
    protected:
        DLNode<T> *head;
        DLNode<T> *tail;
        int size = 0;

    public:
        DLList() : head(nullptr), tail(nullptr) {}

        bool isEmpty() {
            return head == nullptr && tail == nullptr && size == 0;
        }

        DLNode<T>* getHead() const {
            return head;
        }

        DLNode<T>* getTail() const {
            return tail;
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
            ptr->prev = tail;
            tail->next = ptr;
            tail = ptr;
            size++;
        }

        void insertInOrderC(T val) {
            if(this->isEmpty()) {
                this->insert(val);
                return;
            }

            if(val <= head->val) {
                this->insertHead(val);
                return;
            }
            else if(val >= tail->val) {
                this->insertTail(val);
                return;
            }

            DLNode<T> *ptr = head;
            while(ptr->next && val >= ptr->val) {
                if(val <= ptr->next->val) {
                    break;
                }
                ptr = ptr->next;
            }

            DLNode<T> *toInsert = new DLNode<T>(val);
            toInsert->next = ptr->next;
            toInsert->prev = ptr;
            ptr->next->prev = toInsert;
            ptr->next = toInsert;
            size++;
        }

        void insertInOrderD(T val) {
            if(this->isEmpty()) {
                this->insert(val);
                return;
            }

            if(val >= head->val) {
                this->insertHead(val);
                return;
            }
            else if(val <= tail->val) {
                this->insertTail(val);
                return;
            }

            DLNode<T> *ptr = head;
            while(ptr->next && val <= ptr->val) {
                if(val >= ptr->next->val) {
                    break;
                }
                ptr = ptr->next;
            }

            DLNode<T> *toInsert = new DLNode<T>(val);
            toInsert->next = ptr->next;
            toInsert->prev = ptr;
            ptr->next->prev = toInsert;
            ptr->next = toInsert;
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
                delete ptr;
                size--;
                return;
            }

            DLNode<T> *ptr = head;
            head->next->prev = nullptr;
            head = ptr->next;
            delete ptr;
            size--;
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
                size--;
                return;
            }

            DLNode<T> *ptr = tail;
            tail->prev->next = nullptr;
            tail = ptr->prev;
            delete ptr;
            size--;
        }

        void removeNode(T val) {
            if(this->isEmpty()) {
                cout << "Empty list" << endl;
                return;
            }

            if(val == head->val) {
                this->removeHead();
                return;
            }
            else if(val == tail->val) {
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
            delete ptr;
            size--;
        }


        friend ostream& operator<<(ostream& os, DLList<T> &list) {
            os << "List size = " << list.size << ", list head = " << list.head << ", tail = " << list.tail << endl;
            DLNode<T> *ptr = list.head;
            while(ptr) {
                os << '\t' << *ptr << endl;
                ptr = ptr->getNext();
            }
            return os;
        }
};


#endif