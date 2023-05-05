#include <vector>
#include <iostream>
#include <utility>
#include "a.h"
using namespace std;

/*
1. 头文件被多个翻译单元的 include 的时候 静态变量只能初始化一次
*/
/*
2. 类的静态成员如果不在类外提供一个符号, 那么对 A::a 取地址的时候, 链接器会提示没有符号 (undefined reference to A::a ).
*/
// int A::a = 3;
void A::print2() {
    cout << " A print2 :" << A::a << endl;
}
