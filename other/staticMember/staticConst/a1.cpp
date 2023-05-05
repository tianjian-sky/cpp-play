#include <vector>
#include <iostream>
#include <utility>
#include "a.h"
using namespace std;
/*
1. 头文件被多个翻译单元的 include 的时候 静态变量只能初始化一次
*/
/*
2. 只有 const 的 static member 变量支持类内初始化. 但是访问不到地址
类的静态成员如果不在类外提供一个符号, 那么对 A::a 取地址的时候, 链接器会提示没有符号 (undefined reference to A::a ).
*/
// int A::a = 1;
// int A::a = 1; redefinition of 'a'
void A::print1() {
    cout << " A print1 :" << A::a << endl;
}

void B::print1() {
    cout << " B print1 :" << B::aaa << endl;
}
int global = 22;