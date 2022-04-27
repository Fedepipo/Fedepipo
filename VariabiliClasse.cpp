#include<iostream>
using namespace std;

class A {
    int a = 0;

public:
    static int b; //Va dichiarata qui

    A() {
        b++;
    }

    void print() {
        cout << "a = " << a << ", b = " << b << ", address(a) = " << &a << ", address(b) = " << &b << endl;
        //L'indirizzo di a cambia, quello di b rimane lo stesso
    }
};

int A::b = 0; //Va inizializzata qui

int main() {
    A a1;
    a1.print();
    A a2;
    a2.print();
    A a3;
    a3.print();

    /*a1.print();
    a2.print();
    a3.print();*/
}