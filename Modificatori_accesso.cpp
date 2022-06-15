#include<iostream>
using namespace std;

class Base {
    public:
        int n = 10;
};

class Derivata1 : protected Base {

};

class Derivata2 : protected Base {
    public:
        Base::n;
};

int main() {
    Derivata1 d1;
    Derivata2 d2;
    cout << d2.n << endl;
    //cout << d1.n << endl; //ERRORE. In Derivata1 il membro n di Base rimane protected
}