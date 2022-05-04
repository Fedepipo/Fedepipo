#include<iostream>
using namespace std;

class A {
    public:
        A() {
            cout << "constructor A" << endl;
        }
        void foo() {
            cout << "foo A" << endl;
        }
};

class B : {
    public:
        B() {
            cout << "constructor B" << endl;
        }
        void foo() {
            cout << "foo B" << endl;
        }
};

class C {
    public:
        C() {
            cout << "constructor C" << endl;
        }
        void foo() {
            cout << "foo C" << endl;
        }
};

int main() {
    
}