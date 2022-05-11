#include<iostream>
using namespace std;

class A {
    private:
        virtual void private_fun() {
            cout << "Private function di A" << endl;
        }
    public:
        A() {
            cout << "costruttore di A" << endl;
        }
        virtual void stampa() {
            cout << "Sono la classe A" << endl;
        }

        void call_private_virtual() {
            private_fun();
        }
};

class B : public A {
    public:
        B() {
            cout << "costruttore di B" << endl;
        }
        void stampa() {
            cout << "Sono la classe B" << endl;
        }

        void call_private_virtual() {
            cout << "call_private_virtual di B" << endl;
        }
};

int main() {
    A a;
    B b;

    cout << "chiamata ai metodi delle istanze di A e di B" << endl;

    a.stampa(); //utilizza la funzione stampa di A
    b.stampa(); //utilizza la funzione stampa di B

    cout << "Creo dei riferimenti di a e b, e dichiaro entrambi di classe A&" << endl;

    A& ra = a;
    A& rb = b;

    ra.stampa(); //utilizzano entrambe la funzione stampa di A se stampa non è virtual 
    rb.stampa(); //altrimenti il primo usa stampa di A e il secondo stampa di B

    cout << "Creo dei puntatori ad A ed assegno a ciascuno l'indirizzo di a e b" << endl;
    A *pa = &a;
    A *pb = &b;

    pa->stampa(); //utilizzano entrambe la funzione stampa di A se stampa non è virtual
    pb->stampa(); //altrimenti il primo usa stampa di A e il secondo usa stampa di B

    b.call_private_virtual();
    pb->call_private_virtual();
}