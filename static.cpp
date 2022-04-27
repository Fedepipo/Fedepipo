#include<iostream>
using namespace std;

void fun() {
    int a = 0;
    cout << "non static fun a = " << a << endl;
    a++;
}

void fun_static() {
    static int a = 0;
    cout << "static fun a = " << a << endl;
    a++;
}

int main() {
    for(int i=0; i<10; i++) {
        fun_static();
    }
    for(int j=0; j<10; j++) {
        fun();
    }
}