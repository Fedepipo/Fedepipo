#ifndef LIST_H
#define LIST_H
#include<iostream>
#include "Node.h"
using namespace std;

template<typename T>
class List {
    protected:
        Node<T>* head;
        int size = 0;

    public:
        List() {
            this->head = nullptr;
        }

        bool isEmpty() {
            return head == nullptr && size == 0;
        }

        Node<T>* getHead() {
            return this->head;
        }

        void insert(T val) {
            if(this->isEmpty()) {
                head = new Node<T>(val);
                ++size;
                return;
            }
        }

        void insertHead(T val) {
            if(this->isEmpty()) {
                insert(val);
                return;
            }

            Node<T> *ptr = new Node<T>(val);
            
            ptr->next = head;
            head = ptr;
            size++;
        }

        void insertTail(T val) {
            if(this->isEmpty()) {
                insertHead(val);
                return;
            }

            Node<T> *ptr = head;
            while(ptr->next) {
                ptr = ptr->next;
            }

            Node<T> *insert = new Node<T>(val);
            ptr->next = insert;
            insert->next = nullptr;
            size++;
        }

        void insertInOrderC(T val) {
            if(this->isEmpty()) {
                this->insertHead(val);
                return;
            }

            if(val <= head->val) {
                this->insertHead(val);
                return;
            }

            Node<T> *ptr = head;
            while(ptr->next && val >= ptr->val) {
                if(val <= ptr->next->val) {
                    break;
                }
                ptr = ptr->next;
            }

            if(!(ptr->next)) {
                this->insertTail(val);
                return;
            }

            Node<T> *insert = new Node<T>(val);
            insert->next = ptr->next;
            ptr->next = insert;
            size++;
        }

        void insertInOrderD(T val) {
            if(this->isEmpty()) {
                this->insertHead(val);
                return;
            }

            if(val >= head->val) {
                this->insertHead(val);
                return;
            }

            Node<T> *ptr = head;
            while(ptr->next && val <= ptr->val) {
                if(val >= ptr->next->val) {
                    break;
                }
                ptr = ptr->next;
            }

            if(!(ptr->next)) {
                this->insertTail(val);
                return;
            }

            Node<T> *insert = new Node<T>(val);
            insert->next = ptr->next;
            ptr->next = insert;
            size++;
        }

        void removeHead() {
            if(this->isEmpty()) {
                cout << "Empty list" << endl;
                return;
            }

            Node<T> *ptr = head;
            head = head->next;
            size--;
            delete ptr;
        }

        void removeTail() {
            if(this->isEmpty()) {
                cout << "Empty list" << endl;
                return;
            }

            Node<T> *cur = head;
            Node<T> *prev = nullptr;
            while(cur->next) {
                prev = cur;
                cur = cur->next;
            }

            prev->next = nullptr;
            size--;
            delete cur;
        }

        void remove(T val) {
            if(this->isEmpty()) {
                cout << "Empty list" << endl;
                return;
            }
            else if(head->val == val) {
                this->removeHead();
                size--;
                return;
            }

            Node<T> *cur = head;
            Node<T> *prev = nullptr;
            while(cur->next && val != cur->val) {
                prev = cur;
                cur = cur->next;
            }

            if(!(cur->next) && cur->val != val) {
                cout << "Element not found" << endl;
                return;
            }

            prev->next = cur->next;
            size--;
            delete cur;
        }

        friend ostream& operator<<(ostream& os, List<T> &list) {
            os << "head = " << list.head << ", size = " << list.size << endl;
            Node<T> *ptr = list.head;
            while(ptr) {
                os << '\t' << *ptr << endl;
                ptr = ptr->getNext();
            }
            return os;
        }
};



#endif