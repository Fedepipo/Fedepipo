#ifndef LIST_H
#define LIST_H
#include "Node.h"

using namespace std;

template<typename T>
class List {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int counter = 0;

    public:
        List() {
            head = nullptr;
            tail = nullptr;
            cout << head << endl;
        }

        bool isEmpty() { //Controllo lista vuota
            return head == nullptr && tail == nullptr;
        }

        Node<T>* getHead() {
            return head;
        }

        void insert(T val) { //Inserimento in lista vuota
            if(this->isEmpty()) {
                head = new Node<T>(val);
                tail = head;
                ++counter;
                return;
            }
        }

        void insertHead(T val) { //Inserimento in lista non vuota in testa. Complessità O(1)
            if(this->isEmpty()) {
                this->insert(val);
                return;
            }
            Node<T> *temp = new Node<T>(val);
            temp->next = head;
            this->head = temp;
            ++counter;
        }
 
        void insertTail(T val) { //Inserimento in coda. Complessità O(n) senza puntatore alla coda. Con puntatore alla coda complessità O(1)
            if(this->isEmpty()) {
                this->insertHead(val);
                return;
            }

            Node<T> *ptr = head;
            while(ptr->getNext() != nullptr) {
                ptr = ptr->getNext();
            }

            Node<T> *temp = new Node<T>(val);
            ptr->next = temp;
            ++counter;
        }

        void insertInOrderC(T val) { //inserimento in ordine ascendente in lista
            if(this->isEmpty()) {
                this->insertHead(val);
                return;
            }
            if(val <= head->valore) {
                this->insertHead(val);
                return;
            }

            Node<T> *ptr = head;
            while(ptr->next && (val >= ptr->valore)) {
                if(ptr->next->valore >= val) 
                    break;
                ptr = ptr->getNext();
            }

            if(!(ptr->next)) {
                this->insertTail(val);
                return;
            }

            Node<T> *toInsert = new Node<T>(val);
            toInsert->next = ptr->next;
            ptr->next = toInsert;
            ++counter;
        }

        void insertInOrderD(T val) { //inserimento in ordine discendente in lista
            if(this->isEmpty()) {
                this->insertHead(val);
                return;
            }

            if(val >= head->valore) {
                this->insertHead(val);
                return;
            }

            Node<T> *ptr = head;
            while(ptr->next && val <= ptr->valore) {
                if(ptr->next->valore <= val) {
                    break;
                }
                ptr = ptr->next;
            }

            if(!(ptr->next)) {
                this->insertTail(val);
                return;
            }

            Node<T> *temp = new Node<T>(val);
            temp->next = ptr->next;
            ptr->next = temp;
            ++counter;
        }

        void removeHead() { //eliminazione della testa
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }

            Node<T> *temp = head;
            head = head->next;
            --counter;

            delete temp;
        }

        void removeTail() { //eliminazione dell'elemento in coda
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }

            Node<T> *prev = head;
            while(prev->next != tail) {
                prev = prev->next;
            }
            
            Node<T> *temp = tail;
            tail = prev;
            prev->next = nullptr;
            --counter;
            delete temp;
        }

        void removeNode(T val) { //eliminazione di un elemento specifico dentro la lista
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }

            if(val == head->valore) {
                this->removeHead();
                return;
            }

            if(val == tail->valore) {
                this->removeTail();
                return;
            }

            Node<T> *prev = nullptr;
            Node<T> *cur = head;
            while(cur->next && cur->valore != val) {
                prev = cur;
                cur = cur->next;
            }
            if(!(cur->next) && cur->valore != val) {
                cout << "Element with value " << val << " not found" << endl;
                return;
            }
            prev->next = cur->next;
            --counter;
            delete cur;
        }

        void dimensioneLista() {
            cout << "La lista ha " << counter << " elementi" << endl;
        }

        friend ostream& operator<<(ostream& os, const List<T> &list) {
            os << "List head = " << list.head << endl;
            Node<T> *ptr = list.head;
            while(ptr != nullptr) {
                os << '\t' << *ptr << endl;
                ptr = ptr->getNext();
            }
            return os;
        }
};

#endif