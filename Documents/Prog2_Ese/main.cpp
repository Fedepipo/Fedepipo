#include "List.h"
#include "DLList.h"
#include "Stack.h"
#include "Static_Stack.h"
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
    lista.insertInOrderD(4);
    lista.insertInOrderD(3);
    lista.insertInOrderD(6);
    lista.insertInOrderD(15);
    lista.insertInOrderD(8);
    lista.insertHead(5);
    lista.removeTail();
    lista.removeHead();
    lista.insertTail(32);
    lista.removeNode(6);
    lista.removeNode(8);
    lista.removeNode(3);
    lista.removeNode(32);
    


    cout << lista << endl;

  /*  Stack<int> pila;

    pila.push(4);
    pila.push(8);
    pila.push(15);
    pila.push(32);
    pila.push(2);
    pila.pop();
    pila.pop();

    cout << pila << endl;

    Static_Stack<int> s(6);
    
    s.push(4);
    s.push(8);
    s.push(6);
    s.push(15);
    s.push(78);
    s.push(3);
    s.pop();

    cout << s << endl;*/
}