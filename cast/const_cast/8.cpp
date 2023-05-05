#include <vector>
#include <iostream>
#include "a.h"
using namespace std;

/*
1.const_cast 只能转换指针
2. 编译器优化，对const指针转换并修改值时，指针指向地址相同，但是输出结果不同
3.不能使用 const_cast 运算符直接重写常量变量的常量状态
*/
int main () {
    // int b;
    // int b;
    const int c1 = 3;
    int* c2 = const_cast<int*> (&c1);
    *c2 = 88;
    /*
    * 编译器优化，c2与&c1指向地址相同，但是*c2 与 c1 值显示不同
    * 编译时常量替换
    */
    cout << &c1 << ":" << c2 << endl;
    cout << *c2 << ":" << c1  << endl;
    
}