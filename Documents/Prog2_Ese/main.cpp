#include "List.h"
#include "DLList.h"
#include<iostream>
using namespace std;

int main() {
    List<int> list;

    /*list.insertHead(2);
    list.insertHead(4);
    list.insertTail(5);
    list.insertHead(9);
    list.removeHead();
    list.removeTail();
    list.remove(6);*/
    /*list.insertInOrderC(7);
    list.insertInOrderC(21);
    list.insertInOrderC(9);*/
   /* list.insertInOrderD(5);
    list.insertInOrderD(8);
    list.insertInOrderD(25);
    list.insertInOrderD(10);
    cout << list << endl;*/

    DLList<int> lista;
    lista.insertInOrderC(4);
    lista.insertInOrderC(3);
    lista.insertInOrderC(6);
    lista.insertInOrderC(15);
    lista.insertInOrderC(8);
    lista.insertHead(5);
    lista.removeTail();
    lista.removeHead();
    lista.insertTail(32);
    lista.remove(6);
    lista.remove(8);
    lista.remove(3);
    lista.remove(32);
    


    cout << lista << endl;
}