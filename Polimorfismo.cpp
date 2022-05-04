#include<iostream>
using namespace std;

class A {
    public:
        A() {
            cout << "costruttore di A" << endl;
        }
        void stampa() {
            cout << "Sono la classe A" << endl;
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
};

int main() {
    A a;
    B b;

    a.stampa(); //utilizza la funzione stampa di A
    b.stampa(); //utilizza la funzione stampa di B

    A& ra = a;
    A& rb = b;

    ra.stampa(); //utilizzano entrambe la funzione stampa di A
    rb.stampa();

    A *pa = &a;
    A *pb = &b;

    pa->stampa(); //utilizzano entrambe la funzione stampa di A
    pb->stampa();
}