#include<iostream>
using namespace std;

/*void fun() {
    int a = 10;
    cout << "non static fun a= " << a << endl;
}*/

void fun_static() {
    static int a = 10;
    cout << "static fun a = " << a << endl;
}

int main() {
    fun_static();
    cout << a << endl;
}