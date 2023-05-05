#include "a.h"
#include <iostream>
using namespace std;

int main () {
    A a(9,8,7,5,6);
    B b(1,2,3,4, 5);
    // cout << a.d << endl; // protected：可以被该类中的函数、子类的函数、友元函数访问，但不可以由该类的对象访问；
    b.testProtected();
    // b.testPrivate(); // private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象、访问。
}